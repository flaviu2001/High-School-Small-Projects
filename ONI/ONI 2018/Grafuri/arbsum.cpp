#include <fstream>
#include <vector>

using namespace std;

vector<int> v[100005];
int n, d[3][100005], r[100005];
bool ok[100005];
const int inf = 2147483647;

void df(int x)
{
    ok[x] = 1;
    if(v[x].size() == 0){
        d[0][x] = r[x];
        d[1][x] = 0;
        d[2][x] = 0;
    }else{
        for (unsigned i = 0; i < v[x].size(); ++i)
            df(v[x][i]);
        d[0][x] = d[1][x] = d[2][x] = 0;
        for (unsigned i = 0; i < v[x].size(); ++i){
            d[0][x] += max(d[1][v[x][i]], d[2][v[x][i]]);
            d[1][x] += d[0][v[x][i]];
            d[2][x] += max(d[0][v[x][i]], max(d[1][v[x][i]], d[2][v[x][i]]));
        }
        d[0][x] += r[x];
    }
}

int main()
{
    ifstream fin ("arbsum.in");
    ofstream fout ("arbsum.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        d[0][i] = d[1][i] = d[2][i] = inf;
        int x;
        fin >> x;
        if(i != 1)
            v[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        r[i] = x;
    }
    df(1);
    fout << max(d[0][1], max(d[1][1], d[2][1])) << "\n";
    fin.close();
    fout.close();
    return 0;
}

