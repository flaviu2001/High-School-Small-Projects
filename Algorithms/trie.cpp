#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "trie";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

struct trie{
    trie *f[26];
    int ap, aptot;
    trie(){
        memset(f, 0, sizeof(f));
        ap = 0;
        aptot = 0;
    }
    ~trie(){
        for (int i = 0; i < 26; ++i)
            if(f[i] != NULL){
                delete f[i];
                f[i] = NULL;
            }
        ap = aptot = 0;
    }
};

trie *rad = new trie;
int t;
string s;

void add(trie *&t, int p)
{
    ++t->aptot;
    if(p == s.length()){
        ++t->ap;
        return;
    }
    if(t->f[s[p]-'a'] == NULL)
        t->f[s[p]-'a'] = new trie;
    add(t->f[s[p]-'a'], p+1);
}

void rem(trie *&t, int p)
{
    --t->aptot;
    if(p == s.length()){
        --t->ap;
        return;
    }
    if(t->f[s[p]-'a']->aptot == 1){
        delete t->f[s[p]-'a'];
        t->f[s[p]-'a'] = NULL;
    }
    else rem(t->f[s[p]-'a'], p+1);
}

int aparitii(trie *&t, int p)
{
    if(p == s.length())
        return t->ap;
    if(t->f[s[p]-'a'] == NULL)
        return 0;
    return aparitii(t->f[s[p]-'a'], p+1);
}

int prefix(trie *&t, int p)
{
    if(p == s.length())
        return s.length();
    if(t->f[s[p]-'a'] == NULL)
        return p;
    return prefix(t->f[s[p]-'a'], p+1);
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    while(fin >> t >> s)
        if(t == 0)
            add(rad, 0);
        else if (t == 1)
            rem(rad, 0);
        else if (t == 2)
            fout << aparitii(rad, 0) << "\n";
        else fout << prefix(rad, 0) << "\n";
    return 0;
}
