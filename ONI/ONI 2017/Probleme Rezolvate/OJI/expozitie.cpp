#include <fstream>

using namespace std;

typedef int num[501];
int n, d, k, r;
num lc[501], lp[501];

void read();
void solve();
void sum(num, num, num & s);
void write();

int main()
{
    read();
    write();
    return 0;
}

void solve(){
    for (int i = 1; i <= r; ++i)
        lp[i][0] = lp[i][1] = 1;
    for (int i = 2; i <= d; ++i){
        int aux = i;
        lc[1][0] = 0;
        while(aux){
            ++lc[1][0];
            lc[1][lc[1][0]] = aux%10;
            aux /= 10;
        }
        for (int j = 2; j <= r; ++j)
            sum(lp[j], lc[j-1], lc[j]);
        for (int j = 0; j <= r; ++j)
            for (int q = 0; q <= lc[j][0]; ++q)
                lp[j][q] = lc[j][q];
    }
}

void sum(num a, num b, num & s){
    int c, t(0), mx;
    if (a[0] < b[0]){
        mx = b[0];
        for (int i = a[0]+1; i <= b[0]; ++i)
            a[i] = 0;
    }
    else{
        mx = a[0];
        for (int i = b[0]+1; i <= a[0]; ++i)
            b[i] = 0;
    }
    int i;
    for (i = 1; i <= mx; ++i){
        c = a[i] + b[i] + t;
        s[i] = c%10;
        t = c/10;
    }
    if (t)
        s[i] = t;
    else --i;
    s[0] = i;
}

void read(){
    ifstream fin ("expozitie.in");
    fin >> n >> d >> k;
    r = n - k*d;
    fin.close();
}

void write(){
    ofstream fout ("expozitie.out");
    if (r < 0)
        fout << "0\n";
    else if (!r)
        fout << "1\n";
    else{
        solve();
        for (int i = lc[r][0]; i; --i)
            fout << lc[r][i];
    }
    fout.close();
}