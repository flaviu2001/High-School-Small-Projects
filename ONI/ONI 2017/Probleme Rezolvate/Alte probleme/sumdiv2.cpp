#include <fstream>

using namespace std;

long long v[1000009];
int test;

int main()
{
    for (int i = 1; i <= 1000000; ++i)
        for (int j = i; j <= 1000000; j += i)
            v[j] += i;
    for (int i = 2; i <= 1000000; ++i)
        v[i] += v[i-1];

    ifstream fin ("sumdiv2.in");
    ofstream fout ("sumdiv2.out");
    fin >> test;
    while(test--){
        int a, b;
        fin >> a >> b;
        if(a > b){
            int aux = a;
            a = b;
            b = aux;
        }
        fout << v[b] - v[a-1] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

