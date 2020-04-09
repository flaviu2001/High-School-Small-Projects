#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "kinder";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 50005;

struct trie{
    int sum;
    trie *f[2];
    trie(){
        sum = 0;
        memset(f, 0, sizeof(f));
    }
    ~trie(){
        sum = 0;
        if(!f[0]){
            delete f[0];
            f[0] = NULL;
        }if(!f[1]){
            delete f[1];
            f[1] = NULL;
        }
    }
};

int n, M, test, tip0, tip1, ans;
trie *aint[nmax*4][2];
vector<trie*> v;
bool ok[50];

void add(trie *&t, int val, int valf, int pw = 1<<15)
{
    int bit = 0;
    if(val >= pw){
        bit = 1;
        val -= pw;
    }
    if(t == NULL)
        t = new trie;
    t->sum += valf;
    if(t->sum == 0){
        delete t;
        t = NULL;
        return;
    }
    if(t->f[bit] == NULL)
        t->f[bit] = new trie;
    if(pw != 0)
        add(t->f[bit], val, valf, pw/2);
}

int countTrie(trie *&t, int val, int pw = 1<<15)
{
    if(t == NULL)
        return 0;
    if(pw == 0)
        return t->sum;
    int bit = 0;
    if(val >= pw){
        bit = 1;
        val -= pw;
    }
    return countTrie(t->f[bit], val, pw/2);
}

int queryTrie(int x, int pw = 1<<15)
{
    if(pw == 0)
        return 0;
    int constr = 0;
    int bit = 0, sum = 0, p = 0;
    for (auto y : v)
        if(!ok[p++] && y->f[0] != NULL)
            sum += y->f[0]->sum;
    if(sum < x){
        x -= sum;
        constr += pw;
        bit = 1;
    }
    p = 0;
    for (vector<trie*>::iterator it = v.begin(); it != v.end(); ++it)
        if(!ok[p++] && (*it)->f[bit] != NULL)
            (*it) = (*it)->f[bit];
        else if (!ok[p-1])
            ok[p-1] = 1;
    return constr+queryTrie(x, pw/2);
}

void updTrieAint(int nod, int st, int dr, int pos, int val)
{
    if(st == dr){
        tip0 = countTrie(aint[nod][0], val);
        tip1 = countTrie(aint[nod][1], val);
        add(aint[nod][1], val, tip0-tip1);
        add(aint[nod][0], val, tip1-tip0);
        return;
    }
    int m = (st+dr)/2;
    if(m >= pos)
        updTrieAint(nod*2, st, m, pos, val);
    else updTrieAint(nod*2+1, m+1, dr, pos, val);
    add(aint[nod][1], val, tip0-tip1);
    add(aint[nod][0], val, tip1-tip0);
}

void update(int nod, int st, int dr, int pos, int tip, int val, int valf)
{
    add(aint[nod][tip], val, valf);
    if(st != dr){
        int m = (st+dr)/2;
        if(m >= pos)
            update(nod*2, st, m, pos, tip, val, valf);
        else update(nod*2+1, m+1, dr, pos, tip, val, valf);
    }
}

void query(int nod, int st, int dr, int a, int b, int tip)
{
    if(st >= a && dr <= b){
        if(aint[nod][tip] != NULL)
            v.push_back(aint[nod][tip]);
        return;
    }
    int m = (st+dr)/2;
    if(m >= a)
        query(nod*2, st, m, a, b, tip);
    if(m+1 <= b)
        query(nod*2+1, m+1, dr, a, b, tip);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> M >> test;
    while(test--){
        int t;
        fin >> t;
        if(t == 1){
            int pos, val, tip, valf;
            fin >> pos >> val >> tip >> valf;
            update(1, 1, n, pos, tip, val, valf);
        }else if (t == 2){
            int pos, val;
            fin >> pos >> val;
            updTrieAint(1, 1, n, pos, val);
        }else{
            int a, b, tip, k;
            fin >> a >> b >> tip >> k;
            v.clear();
            memset(ok, 0, sizeof(ok));
            query(1, 1, n, a, b, tip);
            fout << queryTrie(k) << "\n";
        }
    }
    return 0;
}
