#include <fstream>
#include <vector>
 
using namespace std;
 
int n, m, mx, vf;
int g[25][25], p[25], v[25];
 
void bkt_biti()
{
    for (int i = 1; i < (1<<n); ++i){
        vf = 0;
        int P = 0;
        for (int j = 0; (1<<j) < (1<<n); ++j)
            if(i & (1<<j))
                v[++vf] = j+1,
                P += p[j+1];
        bool ok = true;
        for (int i = 1; i < vf && ok; ++i)
            for (int j = i+1; j <= vf && ok; ++j)
                if(g[v[i]][v[j]])
                    ok = false;
        if(ok)
            mx = max(mx, P);
    }
}
 
void bkt(vector<int> r, int c)
{
    mx = max(mx, c);
    int i = 1;
    if(r.size())
        i = r.back()+1;
    for (; i <= n; ++i){
        bool ok = true;
        for (vector<int>::iterator it = r.begin(); it != r.end() && ok; ++it)
            if(g[*it][i])
                ok = false;
        if(!ok)
            continue;
        r.push_back(i);
        bkt(r, c+p[i]);
        r.pop_back();
    }
 
}
 
int main()
{
    ifstream fin ("metrou2.in");
    ofstream fout ("metrou2.out");
    fin >> n >> m;
    vector<int> r;
    for (int i = 1; i <= n; ++i){
        fin >> p[i];
    }
    while(m--){
        int x, y;
        fin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    bkt(r, 0);
    //bkt_biti();
    fout << mx << "\n";
    fin.close();
    fout.close();
    return 0;
}
