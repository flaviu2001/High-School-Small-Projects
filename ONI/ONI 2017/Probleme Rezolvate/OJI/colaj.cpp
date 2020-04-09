#include <fstream>
#include <algorithm>

using namespace std;

struct dr{
    int a, b, c, d;
    int pa, pb, pc, pd;
}v[101];

int x[200], y[200];
bool a[210][210];
int n, m, p, x0=1, yy=1, nl, nc, nr, k;

void read();
bool check(int, int, int, int, int);
int pos(int[], int, int);
int src(int[], int);
void positions();
void matrix();
void surround();
void fill(int, int);
void supr();
void write();

int main()
{
    read();
    positions();
    matrix();
    surround();
    supr();
    write();
    return 0;
}

void read(){
    ifstream fin ("colaj.in");
    fin >> n >> m >> p;
    int r(0), xa, xb, xc, xd;
    for (int i = 1; i <= n; ++i){
        fin >> xa >> xb >> xc >> xd;
        if(check(r, xa, xb, xc, xd)){
            v[++r].a = xa;
            v[r].b = xb;
            v[r].c = xc;
            v[r].d = xd;
            x[++k] = xa;
            y[k] = xb;
            x[++k] = xc;
            y[k] = xd;
            if (!v[r].a || !v[r].c)
                --x0;
            if (!v[r].b || !v[r].d)
                --yy;
        }
    }
    sort(x+1, x+k+1);
    sort(y+1, y+k+1);
    n = r;
    fin.close();
}

bool check(int i, int xa, int xb, int xc, int xd){
    for (int j = 1; j <= i; ++j)
        if (v[j].a<xa && v[j].b < xb && v[j].c > xc && v[j].d > xd)
            return 0;
    return 1;
}

void positions(){
    for (int i = 1; i <= n; ++i){
        v[i].pa = src(x, v[i].a);
        v[i].pb = src(y, v[i].b);
        v[i].pc = src(x, v[i].c);
        v[i].pd = src(y, v[i].d);
    }
}

int src(int z[], int a){
    int i = 1, j = k, m;
    while(i <= j){
        m = (i+j)>>1;
        if(z[m] == a)
            return m;
        else if (a < z[m])
            j = m - 1;
        else i = m + 1;
    }
    return i;
}

void matrix(){
    for (int k = 1; k <= n; ++k)
        for (int j = v[k].pa; j < v[k].pc; ++j)
            for (int i = v[k].pb; i < v[k].pd; ++i)
                a[i+yy][j+x0] = 1;
}

void surround(){
    nl = yy + 2*n - 1;
    nc = x0 + 2*n - 1;
    if (m > x[k])
        ++nc;
    if (p > y[k])
        ++nl;
    for (int i = 0; i <= nl+1; ++i)
        a[i][0] = a[i][nc+1] = 1;
    for (int i = 1; i <= nc+1; ++i)
        a[0][i] = a[nl+1][i] = 1;
}

void supr(){
    for (int i = 1; i <= nl; ++i)
        for (int j = 1; j <= nc; ++j)
            if(!a[i][j])
                ++nr,
                fill(i, j);
}

void fill(int i, int j){
    if (!a[i][j]){
        a[i][j] = 1;
        fill(i,j-1);
        fill(i,j+1);
        fill(i-1,j);
        fill(i+1,j);
    }
}

void write(){
    ofstream fout ("colaj.out");
    fout << nr << "\n";
    fout.close();
}
