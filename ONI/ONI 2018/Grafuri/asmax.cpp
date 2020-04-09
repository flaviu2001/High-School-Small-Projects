#include <fstream>
#include <vector>

using namespace std;

vector<int> v[16005];
int c[16005], mx[16005], n, mxxxxxxxxxxxxxxxx = -2000000000;
bool ok[16005];

int df(int x)
{
    ok[x] = 1;
    mx[x] += c[x];
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]]){
            int k = df(v[x][i]);
            if(k > 0)
            mx[x] += k;
        }
    if (mx[x] > mxxxxxxxxxxxxxxxx)
        mxxxxxxxxxxxxxxxx = mx[x];
    return mx[x];
}

int main()
{
    ifstream fin ("asmax.in");
    ofstream fout ("asmax.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> c[i];
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    df(1);
    fout << mxxxxxxxxxxxxxxxx << "\n";
    fin.close();
    fout.close();
    return 0;
}

