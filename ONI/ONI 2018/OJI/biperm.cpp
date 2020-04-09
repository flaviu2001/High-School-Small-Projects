#include <fstream>
#include <vector>

using namespace std;

struct nb{
    int lin[2], col[2];
}r[10005];

bool ok[2][10005], ko[10005];
int n, a[2][10005], sol = 1, p = 0;

void parcurgere(int y, int x)
{
    if(a[y][x] == a[1-y][x]){
        ok[y][x] = ok[1-y][x] = 1;
        sol >>= 1;
        return;
    }
    int thngs = 0, pthngs = 0;
    while(!ok[y][x]){
        ++thngs;
        int y1, x1, z1, z2;
        y1 = r[a[1-y][x]].lin[0];
        x1 = r[a[1-y][x]].col[0];
        ok[y][x] = ok[1-y][x] = 1;
        z2 = 0;
        if(x == x1 && 1-y == y1){
            y1 = r[a[1-y][x]].lin[1];
            x1 = r[a[1-y][x]].col[1];
            z2 = 1;
        }
        z1 = 0;
        if(r[a[1-y1][x1]].lin[0] != 1-y1 || r[a[1-y1][x1]].col[0] != x1)
            z1 = 1;
        if(1-y == y1){
            ++pthngs;
            r[a[1-y1][x1]].lin[z1] = 1 - r[a[1-y1][x1]].lin[z1];
            r[a[1-y][x]].lin[z2] = 1 - r[a[1-y][x]].lin[z2];
            swap(a[y1][x1], a[1-y1][x1]);
        }
        x = x1;
        y = y;
    }
    p += min(pthngs, thngs-pthngs);
}

int main()
{
    ifstream fin ("biperm.in");
    ofstream fout ("biperm.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> a[0][i];
        if(r[a[0][i]].col[0] == 0){
            r[a[0][i]].col[0] = i;
            r[a[0][i]].lin[0] = 0;
        }else{
            r[a[0][i]].col[1] = i;
            r[a[0][i]].lin[1] = 0;
        }
    }
    for (int i = 1; i <= n; ++i){
        fin >> a[1][i];
        if(r[a[1][i]].col[0] == 0){
            r[a[1][i]].col[0] = i;
            r[a[1][i]].lin[0] = 1;
        }else{
            r[a[1][i]].col[1] = i;
            r[a[1][i]].lin[1] = 1;
        }
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= n; ++j)
            if(!ok[i][j])
                sol <<= 1,
                parcurgere(i, j);
    fout << sol << " " << p << "\n";
    for (int i = 0; i < 2; ++i){
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << " ";
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

