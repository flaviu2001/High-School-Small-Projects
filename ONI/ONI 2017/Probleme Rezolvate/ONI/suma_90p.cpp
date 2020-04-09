#include <fstream>

using namespace std;

int a[2000], smax[4][2000], n, p;

int main()
{
    ifstream fin ("suma2.in");
    ofstream fout ("suma2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        if(x < 10)
            a[++p] = x;
        else if(x < 100){
            a[++p] = x/10;
            a[++p] = x%10;
        }else{
            a[++p] = x/100;
            x %= 100;
            a[++p] = x/10;
            a[++p] = x%10;
        }
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2000; ++j)
            smax[i][j] = -1;
    smax[0][0] = 0; smax[1][1] = a[1]; smax[2][1] = a[1] * 10 + a[2];
    if(a[2] > 0)
        smax[2][2] = a[1] + a[2];
    smax[3][1] = a[1] * 100 + a[2] * 10 + a[3];
    if(a[2] > 0)
        smax[3][2] = a[1] + a[2] * 10 + a[3];
    if(a[3] > 0 && smax[3][2] < a[1] * 10 + a[2] + a[3])
        smax[3][2] = a[1] * 10 + a[2] + a[3];
    if(a[2] > 0 && a[3] > 0)
        smax[3][3] = a[1] + a[2] + a[3];

    for (int i = 4; i <= p; ++i){
        smax[i%4][0] = smax[i%4][1] = -1;
        for (int j = 2; j <= i; ++j){
            if(a[i] == 0)
                smax[i%4][j] = -1;
            else if(smax[(i-1+4)%4][j-1] != -1)
                smax[i%4][j] = smax[(i-1+4)%4][j-1] + a[i];
            if(a[i-1] > 0 && smax[(i-2+4)%4][j-1] != -1)
                smax[i%4][j] = max(smax[i%4][j], smax[(i-2+4)%4][j-1] + a[i-1] * 10 + a[i]);
            if(a[i-2] > 0 && smax[(i-3+4)%4][j-1] != -1)
                smax[i%4][j] = max(smax[i%4][j], smax[(i-3+4)%4][j-1] + a[i-2] * 100 + a[i-1] * 10 + a[i]);
        }
    }
    fout << smax[p%4][n] << "\n";
    fin.close();
    fout.close();
    return 0;
}

