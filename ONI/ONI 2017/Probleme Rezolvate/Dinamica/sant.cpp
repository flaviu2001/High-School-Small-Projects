#include <fstream>
#define INF 1<<30

using namespace std;

int v[55][105], pr[55][105], s, n, t, cl[15], cp[15], ans[55];

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    ifstream fin ("sant.in");
    ofstream fout ("sant.out");
    fin >> s >> t >> n;
    for (int i = 1; i <= n; ++i)
        fin >> cl[i] >> cp[i];
    for (int i = 0; i < 55; ++i)
        for (int j = 0; j < 105; ++j)
            v[i][j] = INF;
    for (int i = 1; i <= n; ++i)
        if(v[1][cl[i]] > cp[i]){
            v[1][cl[i]] = cp[i];
            pr[1][cl[i]] = i;
        }
    for (int i = 2; i <= t; ++i)
        for (int j = 1; j <= s; ++j)
            for (int k = 1; k <= n; ++k)
                if(j > cl[k] && v[i-1][j-cl[k]] != INF && v[i-1][j-cl[k]] + cp[k] < v[i][j]){
                    v[i][j] = v[i-1][j-cl[k]] + cp[k];
                    pr[i][j] = k;
                }
    if(v[t][s] == INF)
        fout << "0\n";
    else{
        int J = s;
        for (int i = t; i > 0; --i){
            ans[i] = pr[i][J];
            J -= cl[ans[i]];
        }
        bool ok = 1;
        while(ok){
            ok = 0;
            for (int i = 1; i < t; ++i)
                if(ans[i] > ans[i+1]){
                    int aux = ans[i];
                    ans[i] = ans[i+1];
                    ans[i+1] = aux;
                    ok = 1;
                }
        }
        fout << v[t][s] << "\n";
        for (int i = 1; i <= t; ++i)
            fout << ans[i] << " ";
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

