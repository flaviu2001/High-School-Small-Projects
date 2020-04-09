#include <fstream>

using namespace std;

int m;
long long cost[1000005];

long max(long long x, long long y)
{
    return x > y ? x : y;
}

int main()
{
    ifstream fin ("mobil.in");
    ofstream fout ("mobil.out");
    fin >> m;
    for (int i = 0; i < 31; ++i){
        int x, c = (1<<i);
        fin >> x;
        for (int j = c; j < 1000005; ++j)
            cost[j] = max(cost[j], cost[j-c]+x);
    }
    for (int i = 1; i < 1000005; ++i)
        if (cost[i] >= m){
            fout << i << "\n";
            break;
        }
    fin.close();
    fout.close();
    return 0;
}

