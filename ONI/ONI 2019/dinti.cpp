#include <iostream>
#include <fstream>
 
using namespace std;
 
bool p[1100000], c[1000005];
int n, m, l;
 
int main()
{
    ifstream fin ("dinti.in");
    fin >> n >> m >> l;
    char q;
    for (int i = 0; i < n; ++i)
        fin >> q,
        c[i] = (q == '1');
 
    int k = 0;
    for (int j = 0; j < l; ++j)
        k += (c[j] == 1) ? 0 : (1 << (l-j-1));
    p[k] = 1;
    for (int i = 1; i < n-l+1; ++i){
        if (k >= (1 << (l-1)))
            k -= (1 << (l-1));
        k *= 2;
        if (!c[i+l-1])
            k += 1;
        p[k] = 1;
    }
    for (int j = (1 << l)-1; j >= 0; --j)
            if (p[j])
                for (int ii = 0; ii < l; ++ii)
                    if (j & (1 << ii))
                        p[j ^ (1 << ii)] = 1;
 
    ofstream fout ("dinti.out");
    while(m--){
        int x = 0;
        for (int i = l - 1; i >= 0; --i){
            fin >> q;
            if (q == '1')
                x += (1 << i);
        }
        if (p[x])
            fout << "1\n";
        else fout << "0\n";
    }
    fin.close();
    fout.close();
    return 0;
}
