#include <fstream>
#include <cstring>
#define MAX 210
#define INF 2000000000
#define R 1000003

using namespace std;

char s[MAX], v[] = "aeiouy";
int pos[MAX], n, lg, nr[MAX][2], c, cost[MAX][2];
unsigned char nxt[MAX][MAX];

void read()
{
    ifstream fin ("text.in");
    fin.getline(s, MAX);
    lg = strlen(s);
    fin >> n;
    fin.close();
}

void positions()
{
    int lst = -1;
    for (int i = lg-1; i >= 0; --i){
        if (strchr(v, s[i]))
            lst = i;
        pos[i] = lst;
    }
}

void solve_1()
{
    int sum;
    bool ok;
    c = 0;
    for (int i = 0; i < lg; ++i)
        if (pos[i] != -1 && lg-i <= 20)
            nr[i][0] = 1;
        else nr[i][0] = -1;
    for (int k = 2; k <= n; ++k){
        c = 1 - c;
        for (int i = lg-1; i >= 0; --i){
            nr[i][c] = -1;
            sum = 0; ok = 0;
            for (int t = 1; t <= 20 && i + t - 1 < lg; ++t){
                if (pos[i] == -1 || i + t - 1 < pos[i])
                    continue;
                if (nr[i+t][1-c] != -1){
                    ok = 1;
                    sum = (sum+nr[i+t][1-c])%R;
                }
            }
            if (ok)
                nr[i][c] = sum;
        }
    }
}

void solve_2()
{
    int tmin, mn;
    c = 0;
    for (int i = 0; i < lg; ++i){
        if (pos[i] != -1 && lg-i <= 20){
            cost[i][0] = (lg-i) * (lg-i);
            nxt[i][1] = lg;
        }
        else{
            cost[i][0] = INF;
            nxt[i][1] = 0;
        }
    }
    for (int i = 0; i <= lg; ++i)
        nxt[lg][i] = 0;
    cost[lg][0] = cost[lg][1] = INF;

    for (int k = 2; k <= n; ++k){
        c = 1 - c;
        for (int i = lg-1; i >= 0; --i){
            cost[i][c] = INF;
            nxt[i][k] = 0;
            mn = INF;
            tmin = -1;
            for (int t = 1; t <= 20 && i + t - 1 < lg; ++t){
                if (pos[i] == -1 || i + t - 1 < pos[i])
                    continue;
                if (cost[i+t][1-c] == INF)
                    continue;
                if (cost[i+t][1-c]+t*t < mn){
                    mn = cost[i+t][1-c] + t * t;
                    tmin = t;
                }
            }
            if (tmin != -1){
                cost[i][c] = mn;
                nxt[i][k] = i + tmin;
            }
        }
    }
}

void write()
{
    ofstream fout ("text.out");
    fout << nr[0][c] << "\n" << cost[0][c] << "\n";
    for (int i = 0, k = n; k; --k){
        for (int j = i; j < nxt[i][k]; ++j)
            fout << s[j];
        i = nxt[i][k];
        if (k > 1)
            fout << " ";
    }
    fout.close();
}

int main()
{
    read();
    positions();
    solve_1();
    solve_2();
    write();
    return 0;
}
