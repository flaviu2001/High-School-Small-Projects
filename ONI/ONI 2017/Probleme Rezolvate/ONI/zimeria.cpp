#include <fstream>
#include <cstring>

using namespace std;

int test, n, v[150], mn = 250000, mx, a[250000], k;
char c[6], z[12];

int val(char q[])
{
    int s = 0, p = 1;
    for (int i = 4; i >= 0; --i)
        s += p * v[q[i]],
        p *= 12;
    return s;
}

void cpy(int n)
{
    c[5] = 0;
    for (int i = 4; i >= 0; --i)
        c[i] = z[n % 12],
        n /= 12;
}

void read()
{
    ifstream fin ("zimeria.in");
    fin >> test >> n; fin.get();
    fin.getline(z, 15);
    for (int i = 0; i < 12; ++i)
        v[z[i]] = i;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < 5; ++j)
            fin >> c[j];
        int t = val(c);
        if (t > mx)
            mx = t;
        if (t < mn)
            mn = t;
        if (a[t] == 0)
            ++k;
        ++a[t];
    }
    fin.close();
}

void write()
{
    ofstream fout ("zimeria.out");
    if (test == 1)
        fout << k << "\n";
    else
        for (int i = mn; i <= mx; ++i)
            if (a[i]){
                cpy(i);
                for (int j = 1; j <= a[i]; ++j)
                    fout << c << "\n";
            }
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}

