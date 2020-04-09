#include <fstream>

using namespace std;

bool ok[505][505];
int v[505][505], dp[505][505], n, m, mx;

void read()
{
    ifstream fin ("tort3.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            char q;
            fin >> q;
            v[i][j] = q-'0';
        }
    fin.close();
}

void dinamica()
{
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        dp[i][1] = 1;
    for (int j = 1; j <= m; ++j)
        dp[1][j] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j){
            dp[i][j] = 1;
            if(v[i][j] == v[i-1][j] && v[i][j] == v[i][j-1] && v[i][j] == v[i-1][j-1])
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            mx = max(mx, dp[i][j]);
        }
}

void im_out_of_witty_names_for_functions()
{
    ofstream fout ("tort3.out");
    for (int sz = mx; sz > 0; --sz)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!ok[i][j] && dp[i][j] >= sz && !ok[i-sz+1][j-sz+1] && !ok[i-sz+1][j] && !ok[i][j-sz+1]){
                    fout << sz << " " << i << " " << j << "\n";
                    for (int i1 = i-sz+1; i1 <= i; ++i1)
                        for (int j1 = j-sz+1; j1 <= j; ++j1)
                            ok[i1][j1] = 1;
                }
    fout.close();
}

int main()
{
    read();
    dinamica();
    im_out_of_witty_names_for_functions();
    return 0;
}

