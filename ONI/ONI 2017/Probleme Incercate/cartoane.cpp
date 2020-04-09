#include <fstream>

using namespace std;

int x, y, n, m;

void read();
void swap(int&, int&);
int max(int, int);
int rec(int, int);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    ifstream fin ("cartoane.in");
    fin >> n >> m >> x >> y;
    if (x > y)
        swap(x, y);
    fin.close();
}

void swap(int &t1, int &t2)
{
    int aux = t1;
    t1 = t2;
    t2 = aux;
}

int max(int t1, int t2)
{
    return t1 > t2 ? t1 : t2;
}

int mod(int t1, int t2)
{
    if (t1 < t2)
        return 0;
    return t1%t2;
}

int rec(int a, int b)
{
    if (a > b)
        swap(a, b);
    if ((a < x && a < y) || (b < x && b < y))
        return 0;
    if (a%x == 0 && b%y == 0){
        return (a/x)*(b/y);
    }
    if (b%x == 0 && a%y == 0){
        return (b/x)*(a/y);
    }
    return max(rec(a-(a%x), b-(b%y)) + rec(a, mod(b, y)), rec(a-(a%y), b-(b%x)) + rec(mod(a, y), b));
}

void write()
{
    ofstream fout ("cartoane.out");
    fout << rec(n, m);
    fout.close();
}
