#include <bits/stdc++.h>
 
using namespace std;
 
set<int> s[40005], r[40005], capete[2];
vector< pair<int, int> >ad;
vector<int> v, vd;
int n, test, sq, cnt;
bool yes, gasit, ok[40005], del[40005];
 
void resetOk()
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        ok[*it] = 0;
    v.clear();
}
 
void resetDel()
{
    for (vector<int>::iterator it = vd.begin(); it != vd.end(); ++it)
        del[*it] = 0;
    vd.clear();
}
 
void addOk(int x)
{
    v.push_back(x);
    ok[x] = 1;
}
 
void addDel(int x)
{
    vd.push_back(x);
    del[x] = 1;
}
 
void dfs_capete(int x, int cap)
{
    ++cnt;
    addOk(x);
    if(s[x].size() <= 1)
        capete[cap].insert(x);
    for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
        if(!ok[*it])
            dfs_capete(*it, cap);
}
 
void dfs_capetesq(int x, int cap)
{
    ++cnt;
    addOk(x);
    if(s[x].size() <= 1)
        capete[cap].insert(x);
    int p = 0;
    for(set<int>::iterator it = r[x].begin(); it != r[x].end(); ++it)
        if(!ok[*it]){
            dfs_capetesq(*it, cap);
            ++p;
        }
    if(p == 0)
        dfs_capete(x, cap);
    if(p == 1 && (s[x].size() > r[x].size()))
        for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfs_capete(*it, cap);
}
 
void dfs3(int x, int depth)
{
    ++cnt;
    addOk(x);
    if(depth == 0)
        capete[0].insert(x);
    else{
        for (set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfs3(*it, depth-1);
    }
}
 
void dfsfill(int x, int fil, int depth = sq)
{
    ++cnt;
    addOk(x);
    if(x == fil || gasit){
        gasit = 1;
        return;
    }
    if(depth == 1)
        return;
    for (set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
        if(!ok[*it])
            dfsfill(*it, fil, depth-1);
}
 
void dfs3sq(int x, int depth, int pred = -1)
{
    ++cnt;
    addOk(x);
    if(depth == 0)
        capete[0].insert(x);
    else{
        if(depth < sq){
            if(pred != -1){
                gasit = 0;
                dfsfill(pred, x);
            }
            dfs3(x, depth);
            return;
        }
        int p = 0;
        for (set<int>::iterator it = r[x].begin(); it != r[x].end(); ++it)
            if(!ok[*it]){
                dfs3sq(*it, depth-sq, x);
                ++p;
            }
    }
}
 
void dfsAddConstruct(int x, int depth = 1)
{
    ++cnt;
    addOk(x);
    ad.push_back(make_pair(x, depth));
    if(depth < sq)
        for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfsAddConstruct(*it, depth+1);
}
 
void dfsAddAdd(int x, int depth = 1)
{
    ++cnt;
    addOk(x);
    if(ad.back().second+depth-1 == sq){
        r[x].insert(ad.back().first);
        ad.pop_back();
    }
    if(depth < sq)
        for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfsAddAdd(*it, depth+1);
}
 
void dfsDelConstruct(int x, int depth = sq-1)
{
    ++cnt;
    addDel(x);
    addOk(x);
    if(depth>0)
        for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfsDelConstruct(*it, depth-1);
}
 
void dfsDelDelete(int x, int depth = sq-1)
{
    ++cnt;
    addOk(x);
    for(set<int>::iterator it = r[x].begin(); it != r[x].end(); ++it)
        if(del[*it])
            r[x].erase(it);
    if(depth>0)
        for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
            if(!ok[*it])
                dfsDelDelete(*it, depth-1);
}
 
int main()
{
    ifstream fin ("drumuri4.in");
    ofstream fout ("drumuri4.out");
    fin >> n >> test;
    sq = sqrt(n);
    while(test--){
        int x, y, t;
        fin >> t >> x;
        if(t != 4)
            fin >> y;
        switch(t){
            case 1:
                yes = true;
                if(s[x].find(y) != s[x].end() || s[x].size() == 2 || s[y].find(x) != s[y].end() || s[y].size() == 2)
                    yes = false;
                if(yes){
                    capete[0].clear();
                    capete[1].clear();
                    resetOk();
                    dfs_capetesq(x, 0);
                    resetOk();
                    dfs_capetesq(y, 1);
                    if(*(capete[0].begin()) == *(capete[1].begin()))
                        yes = false;
                }
                if(yes){
                    resetOk();
                    ad.clear();
                    dfsAddConstruct(x);
                    resetOk();
                    dfsAddAdd(y);
 
                    resetOk();
                    ad.clear();
                    dfsAddConstruct(y);
                    resetOk();
                    dfsAddAdd(x);
 
                    s[x].insert(y);
                    s[y].insert(x);
                }
                fout << yes << "\n";
                break;
            case 2:
                yes = false;
                if(s[x].find(y) != s[x].end()){
                    s[x].erase(s[x].find(y));
                    yes = true;
                }
                if(s[y].find(x) != s[y].end())
                    s[y].erase(s[y].find(x));
                if(yes){
                    resetOk();
                    resetDel();
                    dfsDelConstruct(x);
                    dfsDelConstruct(y);
                    resetOk();
                    dfsDelDelete(x);
                    dfsDelDelete(y);
                }
                fout << yes << "\n";
                break;
            case 3:
                capete[0].clear();
                resetOk();
                dfs3sq(x, y);
                fout << capete[0].size() << " ";
                for (set<int>::iterator it = capete[0].begin(); it != capete[0].end(); ++it)
                    fout << *it << " ";
                fout << "\n";
                break;
            case 4:
                capete[0].clear();
                resetOk();
                dfs_capetesq(x, 0);
                fout << capete[0].size() << " ";
                for (set<int>::iterator it = capete[0].begin(); it != capete[0].end(); ++it)
                    fout << *it << " ";
                fout << "\n";
                break;
        }
    }
    //cout << cnt;
    fin.close();
    fout.close();
    return 0;
}
