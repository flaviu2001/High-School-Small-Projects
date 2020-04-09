#include <fstream>
#define M 666013

using namespace std;

int n, k, w, r[2][1000001], p;

int main()
{
    ifstream fin ("nmult.in");
    ofstream fout ("nmult.out");
    fin >> n >> k >> w;
    for (int i = 1; i <= n; ++i)
        r[p][i] = i % M;
    for (int ik = 2; ik <= k; ++ik){
        r[1-p][w*(ik-1)+1] = 1;
        for (int i = w*(ik-1)+2; i <= n; ++i)
            r[1-p][i] = (r[1-p][i-1] % M + r[p][i-w] % M) % M;
        p = 1-p;
    }
    fout << r[p][n] << "\n";
    fin.close();
    fout.close();
    return 0;
}

