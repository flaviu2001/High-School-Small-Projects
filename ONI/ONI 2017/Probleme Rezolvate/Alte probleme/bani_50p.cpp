#include <fstream>
#include <vector>

using namespace std;

vector< vector<long long> > r;
vector<short> v;
int n, t;

void read()
{
    ifstream fin ("bani.in");
    fin >> n >> t;
    r.resize(t+1);
    for (int i = 0; i < t+1; ++i)
        r[i].resize(n, -1);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    fin.close();
}

long long pleaseWork(int sum, int k)
{
    if(r[sum][k] != -1)
        return r[sum][k];
    if(sum == 0){
        r[sum][k] = 1;
        return 1;
    }
    if(k == 0 && sum % v[0] == 0){
        r[sum][0] = 1;
        return 1;
    }
    if(k == 0){
        r[sum][0] = 0;
        return 0;
    }

    long long x = 0;
    for (int i = 0; i <= k; ++i)
        if(sum >= v[k-i]){
            if(r[sum-v[k-i]][k-i] == -1)
                r[sum-v[k-i]][k-i] = pleaseWork(sum-v[k-i], k-i);
            x += r[sum-v[k-i]][k-i];
        }
    r[sum][k] = x;
    return x;
}

void write()
{
    ofstream fout ("bani.out");
    fout << pleaseWork(t, n-1) << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}

