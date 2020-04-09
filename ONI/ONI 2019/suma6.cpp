#include <bits/stdc++.h>

using namespace std;

struct query{
    int x, y, i;
    bool operator<(const query &obj)const{
        if(y != obj.y)
            return y < obj.y;
        return x < obj.x;
    }
};

const int nmax = 100005, valmax = 1000006;
int n, s, test, sq, v[nmax], cnt[valmax];
long long sol[2*nmax];
vector<query> m[1005];

query mkq(int x, int y, int i)
{
    query a;
    a.x = x;
    a.y = y;
    a.i = i;
    return a;
}

int main()
{
    ifstream fin ("suma6.in");
    ofstream fout ("suma6.out");
    fin >> n >> s; sq =  sqrt(n);
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> test;
    for (int i = 1; i <= test; ++i){
        int x, y;
        fin >> x >> y;
        //--x;
        m[x/sq].push_back(mkq(x, y, i));
    }
    for (int i = 0; i < 1005; ++i)
        sort(m[i].begin(), m[i].end());
    for (int t = 0; t < 1005; ++t)
        if(m[t].size() != 0){
            query q = *m[t].begin();
            long long ans = 0;
            for (int i = q.x; i <= q.y; ++i){
                if(s-v[i] >= 0)
                    ans += cnt[s-v[i]];
                ++cnt[v[i]];
            }
            sol[q.i] = ans;
            int lx = q.x, ly = q.y;
            for (vector<query>::iterator it = m[t].begin()+1; it != m[t].end(); ++it){
                int x = it->x, y = it->y;
                for (int i = lx; i <= x-1; ++i){
                    --cnt[v[i]];
                    if(s-v[i] >= 0)
                        ans -= cnt[s-v[i]];
                }
                for (int i = lx-1; i >= x; --i){
                    if(s-v[i] >= 0)
                        ans += cnt[s-v[i]];
                    ++cnt[v[i]];
                }
                for (int i = ly+1; i <= y; ++i){
                    if(s-v[i] >= 0)
                        ans += cnt[s-v[i]];
                    ++cnt[v[i]];
                }
                sol[it->i] = ans;
                lx = x, ly = y;
            }
            for (int i = lx; i <= ly; ++i)
                --cnt[v[i]];
        }
    for (int i = 1; i <= test; ++i)
        fout << sol[i] << "\n";
    return 0;
}

