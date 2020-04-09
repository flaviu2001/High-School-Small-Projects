#include <fstream>

using namespace std;

long long test, n, m, vv, xn, xs, yv, ye, v[1005][1005], st, pd[1005][1005];

void read()
{
    ifstream fin ("fence.in");
    fin >> test >> n >> m >> vv >> xn >> xs >> yv >> ye;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j],
            st += v[i][j];
    fin.close();
}

long long cerinta1()
{
    long long de_scazut = 0, k = 0;
    for (int i = 1; i < yv; ++i)
        for (int j = 1; j < xn; ++j)
            de_scazut += v[i][j],
            ++k;
    for (int i = 1; i < ye; ++i)
        for (int j = xn+1; j <= m; ++j)
            de_scazut += v[i][j],
            ++k;
    for (int i = yv+1; i <= n; ++i)
        for (int j = 1; j < xs; ++j)
            de_scazut += v[i][j],
            ++k;
    for (int i = ye+1; i <= n; ++i)
        for (int j = xs+1; j <= m; ++j)
            de_scazut += v[i][j],
            ++k;
    return st - de_scazut - vv * (n*m-k);
}

long long cerinta2()
{
    long long base = cerinta1(), mx1 = 0, mx2 = 0, mx3 = 0, mx4 = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] -= vv;

    /* NORTH WEST */

    long long maxime[1005] = {0};
    for (int i = yv-1; i > 0; --i){
        pd[i][xn-1] = pd[i+1][xn-1] + v[i][xn-1];
        mx1 = max(mx1, pd[i][xn-1]);
    }
    maxime[1] = pd[1][xn-1];
    for (int i = 2; i < yv; ++i)
        maxime[i] = max(maxime[i-1], pd[i][xn-1]);
    for (int j = xn-2; j > 0; --j){
        long long r[1005] = {0};
        for (int i = yv-1; i > 0; --i){
            r[i] = r[i+1] + v[i][j];
            pd[i][j] = maxime[i] + r[i];
            mx1 = max(mx1, pd[i][j]);
        }
        maxime[1] = pd[1][j];
        for (int i = 2; i < yv; ++i)
            maxime[i] = max(maxime[i-1], pd[i][j]);
    }

    /* NORTH WEST */


    /* ********** */


    /* NORTH EAST */

    for (int i = 0; i < 1005; ++i)
        maxime[i] = 0;
    for (int i = ye-1; i > 0; --i){
        pd[i][xn+1] = pd[i+1][xn+1] + v[i][xn+1];
        mx2 = max(mx2, pd[i][xn+1]);
    }
    maxime[1] = pd[1][xn+1];
    for (int i = 2; i < ye; ++i)
        maxime[i] = max(maxime[i-1], pd[i][xn+1]);
    for (int j = xn+2; j <= m; ++j){
        long long r[1005] = {0};
        for (int i = ye-1; i > 0; --i){
            r[i] = r[i+1] + v[i][j];
            pd[i][j] = maxime[i] + r[i];
            mx2 = max(mx2, pd[i][j]);
        }
        maxime[1] = pd[1][j];
        for (int i = 2; i < ye; ++i)
            maxime[i] = max(maxime[i-1], pd[i][j]);
    }

    /* NORTH EAST */


    /* ********** */


    /* SOUTH WEST */

    for (int i = 0; i < 1005; ++i)
        maxime[i] = 0;
    for (int i = yv+1; i <= n; ++i){
        pd[i][xs-1] = pd[i-1][xs-1] + v[i][xs-1];
        mx3 = max(mx3, pd[i][xs-1]);
    }
    maxime[n] = pd[n][xs-1];
    for (int i = n-1; i > yv; --i)
        maxime[i] = max(maxime[i+1], pd[i][xs-1]);
    for (int j = xs-2; j > 0; --j){
        long long r[1005] = {0};
        for (int i = yv+1; i <= n; ++i){
            r[i] = r[i-1] + v[i][j];
            pd[i][j] = maxime[i] + r[i];
            mx3 = max(mx3, pd[i][j]);
        }
        maxime[n] = pd[n][j];
        for (int i = n-1; i > yv; --i)
            maxime[i] = max(maxime[i+1], pd[i][j]);
    }

    /* SOUTH WEST */


    /* ********** */


    /* SOUTH EAST */

    for (int i = 0; i < 1005; ++i)
        maxime[i] = 0;
    for (int i = ye+1; i <= n; ++i){
        pd[i][xs+1] = pd[i-1][xs+1] + v[i][xs+1];
        mx4 = max(mx4, pd[i][xs+1]);
    }
    maxime[n] = pd[n][xs+1];
    for (int i = n-1; i > ye; --i)
        maxime[i] = max(maxime[i+1], pd[i][xs+1]);
    for (int j = xs+2; j <= m; ++j){
        long long r[1005] = {0};
        for (int i = ye+1; i <= n; ++i){
            r[i] = r[i-1] + v[i][j];
            pd[i][j] = maxime[i] + r[i];
            mx4 = max(mx4, pd[i][j]);
        }
        maxime[n] = pd[n][j];
        for (int i = n-1; i > ye; --i)
            maxime[i] = max(maxime[i+1], pd[i][j]);
    }

    /* SOUTH EAST */
    return base + mx1 + mx2 + mx3 + mx4;
}

void write()
{
    ofstream fout ("fence.out");
    if(test == 1)
        fout << cerinta1() << "\n";
    else
        fout << cerinta2() << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}

