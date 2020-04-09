#include <fstream>
#include <iomanip>

using namespace std;


long cmmdc(long a, long b)
{
    long r;
    while (b)
      {
          r=a%b;
          a=b;
          b=r;
      }
    return a;
}

int main()
{
    long n,m,N,M,CMMDC,nl,nh;
    long long s;
    int colt=0;
    ifstream fin("reflex.in");
    ofstream fout("reflex.out");
    fin >> n >> m;
    N = n - 1;
    M = m - 1;
    CMMDC = cmmdc(N, M);
    nl = N / CMMDC;
    nh = M / CMMDC;
    if ( nl % 2 == 0 )
         colt = 4;
    else if ( nh % 2 == 0 )
          colt=2;
    else colt=3;
    s = nl;
    s = s * M + 1;
    fout << s << " " << colt << "\n";
    fout << nh -1 << " " << nl -1 << "\n";
    return 0;
}
