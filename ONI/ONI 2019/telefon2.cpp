#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const int nmax = 100005;

int n, go[nmax], lasts[nmax];
vector<int> v[nmax];
unordered_set<int> s, s2;
vector< pair<int, int> > sol;
pair<int, int> ad[nmax];
int ok[nmax], last;

void ciclu(int x)
{
    ok[x] = 2;
    if(!ok[go[x]])
        ciclu(go[x]);
    else if(ok[go[x]] == 2)
        s.insert(go[x]);
    ok[x] = 1;
}

void normalize_tree(int x)
{
    bool first = true;
    if(v[x].size() == 0)
        last = x;
	for (auto y : v[x]){
        if(!first)
            sol.push_back({y, last});
        first = false;
        normalize_tree(y);
    }
}

void normalize_cicle(int x)
{
    int nod = go[x], pred = x, predl=-1, guy = -1;
    do{
        ok[nod] = 0;
        for (auto y : v[nod])
            if(y != pred){
                guy = y;
                predl = pred;
                normalize_tree(y);
                lasts[y] = last;
            }
        pred = nod;
        nod = go[nod];
    }while(pred != x);

    nod = go[x], pred = x;
    do{
        for (auto y : v[nod])
            if(y != pred && y != guy){
                sol.push_back({y, last});
                last = lasts[y];
            }
        if(predl == -1 && nod == x){
            guy = x;
            predl = pred;
            last = x;
        }
        pred = nod;
        nod = go[nod];
    }while(pred != x);
    lasts[guy] = last;
    ad[x] = {predl, guy};
}

int main()
{
    ifstream fin ("telefon2.in");
    ofstream fout ("telefon2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> go[i];
        v[go[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if(!ok[i])
            ciclu(i);
    for (auto x : s)
        if(ok[x]){
            normalize_cicle(x);
            s2.insert(x);
        }
    bool first = true;
    if(s2.size() == 1){
        int x = *s2.begin();
        if(go[ad[x].ff] != ad[x].ss)
            sol.push_back({ad[x].ff, lasts[ad[x].ss]});
    }else{
        int pred, last2=-1;
        for (auto x : s2){
            if(first){
                last = lasts[ad[x].ss];
                pred = ad[x].first;
                first = false;
                continue;
            }
            last2 = ad[x].ff;
            sol.push_back({pred, lasts[ad[x].ss]});
        }
        sol.push_back({last2, last});
    }
    fout << sol.size() << "\n";
    for (auto x : sol)
        fout << x.ff << " " << x.ss << "\n";
    return 0;
}

