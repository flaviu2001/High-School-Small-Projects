#include <fstream>
#define M 666013

using namespace std;

short n, v[2005], lv[2005][2005], mxx = 1; // lv[i][j] - lungimea subsirului palindrom maxim cuprins intre i si j
int r[2005][2005]; // r[i][j] - nr de subsiruri palindroame maxime cuprinse intre i si j

void rec(short i1, short j1)
{
    if(j1 == i1){
        r[i1][j1] = 1;
        lv[i1][j1] = 1;
        return;
    }
    if(j1 < i1){
        r[i1][j1] = 1;
        lv[i1][j1] = 0;
        return;
    }
    if(r[i1][j1] != -1)
        return;

    short mx = 1;
    int k = j1-i1+1;
    for (short i = i1; i < j1; ++i)
        for (short j = j1; j > i; --j)
            if(v[i] == v[j]){
                rec(i+1, j-1);
                short x = lv[i+1][j-1];
                if(x + 2 > mx){
                    mx = x + 2;
                    k = r[i+1][j-1];
                    k %= M;
                }else if(x+2 == mx){
                    k += r[i+1][j-1];
                    k %= M;
                }
            }
    if(mx > mxx)
        mxx = mx;

    k %= M;
    lv[i1][j1] = mx;
    r[i1][j1] = k;
}

int main()
{
    ifstream fin ("maxpal.in");
    ofstream fout ("maxpal.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];

    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < n+1; ++j)
            r[i][j] = -1;
    rec(1, n);
    fout << mxx << " " << r[1][n] << "\n";
    return 0;
}

