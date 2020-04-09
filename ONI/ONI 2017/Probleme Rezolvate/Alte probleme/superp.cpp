#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> q;
int dx[] = {1, 3, 7, 9};

bool isPrime(long long x)
{
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x%i == 0)
            return false;
    return true;
}

void que()
{
    q.push_back(2);
    q.push_back(3);
    q.push_back(5);
    q.push_back(7);
    unsigned p = 0;
    while(p < q.size()){
        long long k = q[p];
        for (int i = 0; i < 4; ++i){
            long long x = k * 10 + dx[i];
            if (x < 10000000000000 && isPrime(x))
                q.push_back(x);
        }
        ++p;
    }
}

bool check(long long y, long long x)
{
    int v1[15] = {0};
    int v2[15] = {0};
    while(y){
        ++v1[y%10];
        y /= 10;
    }
    while(x){
        ++v2[x%10];
        x /= 10;
    }
    for (int i = 0; i < 15; ++i)
        if (v1[i] > v2[i])
            return false;
    return true;
}

long long biggestPrime(long long x)
{
    long long y = x, z = 0, mx = 0;
    vector<int> v;
    while(y){
        v.push_back(y%10);
        y /= 10;
    }
    sort(v.begin(), v.end());
    for (int i = v.size()-1; i >= 0; --i)
        z = z * 10 + v[i];

    for (unsigned i = 0; i < q.size() && q[i] <= z; ++i)
        if (check(q[i], z))
            mx = q[i];
    return mx;
}

int main()
{
    que();
    ifstream fin ("superp.in");
    ofstream fout ("superp.out");
    int m;
    fin >> m;
    while(m--){
        long long x;
        fin >> x;
        fout << biggestPrime(x) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
