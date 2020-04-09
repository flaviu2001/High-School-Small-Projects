#include <fstream>
#define M 9001

using namespace std;

int n, r[10005];

int main()
{
    ifstream fin ("flori4.in");
    ofstream fout ("flori4.out");
    fin >> n;
    r[1] = 1;
    r[2] = 2;
    for (int i = 3; i <= n; ++i)
        r[i] = (r[i-1] + r[i-2] + 1) % M; // ca la fibonacci numa ca mai adaugi unu la fiecare pas
    fout << r[n];
    return 0;
}
