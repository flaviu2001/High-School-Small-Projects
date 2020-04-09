#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, p;
    bool operator<(const thing &obj)const{
        return x < obj.x;
    }
};

//set<thing> s;
map<int, int> s;
int n, m, k, p, v[305][305];
int ok[305*305+305];

thing make_thing (int x, int p)
{
    thing aux;
    aux.x = x;
    aux.p = p;
    return aux;
}

bool can_be_made(int t)
{
    memset(ok, 0, sizeof(ok));
    int cnt = 0;
    for (int i = 1; i <= t; ++i)
        for (int j = 1; j <= t; ++j){
            if(!ok[v[i][j]])
                ++cnt;
            ++ok[v[i][j]];
        }
    if(cnt<=k)
        return true;
    for (int i = 1; i <= n-t+1; ++i){
        if(i%2==1){
            for (int j = 2; j <= m-t+1; ++j){
                for (int i1 = i; i1 <= i+t-1; ++i1){
                    --ok[v[i1][j-1]];
                    if(!ok[v[i1][j-1]])
                        --cnt;
                    if(!ok[v[i1][j+t-1]])
                        ++cnt;
                    ++ok[v[i1][j+t-1]];
                }
                if(cnt<=k)
                    return true;
            }
            if(i != n-t+1){
                for(int i1 = m; i1 >= m-t+1; --i1){
                    --ok[v[i][i1]];
                    if(!ok[v[i][i1]])
                        --cnt;
                    if(!ok[v[i+t][i1]])
                        ++cnt;
                    ++ok[v[i+t][i1]];
                }
                if(cnt<=k)
                    return true;
            }
        }else{
            for (int j = m-1; j-t+1 > 0; --j){
                for (int i1 = i; i1 <= i+t-1; ++i1){
                    --ok[v[i1][j+1]];
                    if(!ok[v[i1][j+1]])
                        --cnt;
                    if(!ok[v[i1][j-t+1]])
                        ++cnt;
                    ++ok[v[i1][j-t+1]];
                }
                if(cnt<=k)
                    return true;
            }
            if(i != n-t+1){
                for (int i1 = 1; i1 <= t; ++i1){
                    --ok[v[i][i1]];
                    if(!ok[v[i][i1]])
                        --cnt;
                    if(!ok[v[i+t][i1]])
                        ++cnt;
                    ++ok[v[i+t][i1]];
                }
                if(cnt<=k)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream fin ("submatrix.in");
    ofstream fout ("submatrix.out");
    fin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x;
            fin >> x;
            if(s.find(x) == s.end())
                s[x] = ++p;
            v[i][j] = s[x];
        }
    int i, step, mn = min(n, m);
    for(step = 1; step <= mn; step <<= 1);
    for(i = 0; step; step >>= 1)
        if(i+step <= mn && can_be_made(i+step))
            i += step;
    fout << i << "\n";
    fin.close();
    fout.close();
    return 0;
}

