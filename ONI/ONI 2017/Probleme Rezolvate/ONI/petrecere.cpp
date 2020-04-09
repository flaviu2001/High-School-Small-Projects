#include <fstream>
#define MAX 3005

using namespace std;

int n, a[MAX], na, b[MAX], nb, c[MAX], nc;

void read();
void solve();
void copy(int[], int&, int[], int);
void sum(int[], int, int[], int, int[], int&);
void prod(int[], int &, int);
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read(){
    ifstream fin ("petrecere.in");
    fin >> n;
    fin.close();
}

void solve(){
    if (n == 1){
        c[1] = 1;
        nc = 1;
        return;
    } else if (n == 2){
        c[1] = 2;
        nc = 1;
        return;
    }
    a[1] = 1;
    b[1] = 2;
    na = nb = 1;
    for(int i = 3; i <= n; ++i){
        prod(a, na, i-1);
        sum(a, na, b, nb, c, nc);
        copy(a, na, b, nb);
        copy(b, nb, c, nc);
    }
}

void copy(int a[], int &na, int b[], int nb){
    na = nb;
    for (int i = 1; i <= na; ++i)
        a[i] = b[i];
}

void sum(int a[], int na, int b[], int nb, int c[], int &nc){
    int t(0);
    nc = na > nb ? na : nb;
    for (int i = 1; i <= nc; ++i){
        c[i] = a[i] + b[i] + t;
        if (c[i] > 9){
            c[i] -= 10;
            t = 1;
        }
        else t = 0;
    }
    if (t)
        c[++nc] = t;
}

void prod(int a[], int &na, int x){
    int t(0), p;
    for (int i = 1; i <= na; ++i){
        p = a[i] * x + t;
        a[i] = p % 10;
        t = p / 10;
    }
    while(t)
        a[++na] = t % 10,
        t /= 10;
}

void write(){
    ofstream fout ("petrecere.out");
    for (int i = nc; i; --i)
        fout << c[i];
    fout.close();
}

