#include <fstream>

using namespace std;

int dx[] = {-1, -1, 0, 0}, dy[] = {-1, 0, -1, 0};
int t, ax, n, v[60][60][60], pd[60][60][60], prx[60][60][60], pry[60][60][60], mn = 1<<30, I, J, sq[100], ans[100];

bool check(int i, int i1, int j1)
{
    return (i1 > 0 && j1 > 0 && i1 <= i && j1 <= i);
}

int main()
{
    ifstream fin ("suma4.in");
    ofstream fout ("suma4.out");
    fin >> n;
    while(ax < n)
        ++t,
        ax += t * t,
        sq[t] = ax;
    for (int i = 1; i <= t; ++i)
        for (int i1 = 1; i1 <= i; ++i1)
            for (int j1 = 1; j1 <= i; ++j1)
                fin >> v[i][i1][j1];

    pd[1][1][1] = v[1][1][1];
    prx[1][1][1] = pry[1][1][1] = -1;
    for (int i = 2; i <= t; ++i){
        for (int i1 = 1; i1 <= i; ++i1)
            for (int j1 = 1; j1 <= i; ++j1){
                for (int k = 0; k < 4; ++k)
                    if(check(i-1, i1+dx[k], j1+dy[k])){
                        if(pd[i][i1][j1] > pd[i-1][i1+dx[k]][j1+dy[k]] + v[i][i1][j1] || pd[i][i1][j1] == 0){
                            pd[i][i1][j1] = pd[i-1][i1+dx[k]][j1+dy[k]] + v[i][i1][j1];
                            prx[i][i1][j1] = i1+dx[k];
                            pry[i][i1][j1] = j1+dy[k];
                        }
                    }
                if(i == t && pd[i][i1][j1] < mn){
                    mn = pd[i][i1][j1];
                    I = i1;
                    J = j1;
                }
            }
    }
    fout << t << " " << mn << "\n";
    for (int i = t; i > 0; --i){
        int x;
        x = sq[i-1] + (I-1)*i + J;
        ans[i] = x;
        int ii = prx[i][I][J], jj = pry[i][I][J];
        I = ii;
        J = jj;
    }
    for (int i = 1; i <= t; ++i)
        fout << ans[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

