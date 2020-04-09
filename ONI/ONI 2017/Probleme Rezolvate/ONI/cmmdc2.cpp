#include <fstream>

using namespace std;

int f[1000005], mx(0), n, t;

void read()
{
    ifstream fin ("cmmdc2.in");
    fin >> n >> t;
    int x;
    for (int i = 1; i <= n; ++i){
        fin >> x;
        ++f[x];
        if(x > mx)
            mx = x;
    }
    fin.close();
}

int getK()
{
    for (int i = mx; i; --i){
        int k = 0;
        for (int d = i; d <= mx; d += i)
            k += f[d];
        if(k >= t)
            return i;
    }
    return 1;
}

void write()
{
    ofstream fout ("cmmdc2.out");
    int k = getK(), c = 0;
    fout << k << "\n";
    for (int i = mx; i && c < t; --i)
        if (i % k == 0)
            for (int d = 1; d <= f[i] && c < t; ++d)
                ++c,
                fout << i << " ";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
