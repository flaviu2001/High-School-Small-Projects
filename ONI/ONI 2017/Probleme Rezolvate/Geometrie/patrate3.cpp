#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin ("patrate3.in");
    ofstream fout ("patrate3.out");
    double k, q;
    fin >> k;
    q = sqrt (2) * 2 - sqrt(k) * sqrt(2);
    fout << fixed << setprecision(11) << q;
    fin.close();
    fout.close();
    return 0;
}
