#include <bits/stdc++.h>

using namespace std;

int n, m, k, pdsz[55], pdnr[55];
string ans;
set<int> v[55];
bool start[55];

int con(char q)
{
    if(q >= 'a' && q <= 'z')
        return q-'a';
    return q-'A'+'z'-'a'+1;
}

char con2(int x)
{
    if(x <= 25)
        return char(x+'a');
    return char(x-'z'+'a'-1+'A');
}

void dfs(int x)
{
    if(pdsz[x] != 0)
        return;
    if(v[x].size() == 0){
        pdsz[x] = 1;
        pdnr[x] = 1;
    }
    for (auto y : v[x]){
        dfs(y);
        if(pdsz[y]+1 > pdsz[x]){
            pdsz[x] = pdsz[y]+1;
            pdnr[x] = pdnr[y];
        }else if (pdsz[y]+1 == pdsz[x]){
            pdnr[x] += pdnr[y];
        }
    }
}

void dfs_construct(int x, int need)
{
    ans += con2(x);
    for (auto y : v[x])
        if(pdsz[y] == need)
            if(pdnr[y] < k)
                k -= pdnr[y];
            else{
                dfs_construct(y, need-1);
                break;
            }
}

int main()
{
    ifstream fin ("path.in");
    ofstream fout ("path.out");
    fin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        char x, y;
        fin >> x >> y;
        v[con(x)].insert(con(y));
        start[con(y)] = 1;
    }
    int mx = 0;
    for (int i = 0; i <= con('Z'); ++i)
        if(!start[i] && v[i].size() != 0){
            dfs(i);
            mx = max(mx, pdsz[i]);
        }
    for (int i = 0; i <= con('Z'); ++i)
        if(!start[i] && v[i].size() != 0 && pdsz[i] == mx)
            if(pdnr[i] < k)
                k -= pdnr[i];
            else{
                dfs_construct(i, mx-1);
                break;
            }
    fout << ans << "\n";
    return 0;
}

