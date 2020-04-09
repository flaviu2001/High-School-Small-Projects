#include <fstream>
#include <vector>

using namespace std;

vector<int> v;
int n, sum, mxx;
bool ok[707];

void read()
{
    ifstream fin ("cds.in");
    fin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        fin >> x;
        sum += x;
        v.push_back(x);
    }
    fin.close();
}

void solve()
{
    ok[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 700-v[i]; j >= 0; --j)
            if(ok[j])
                ok[j+v[i]] = 1;
    for (int i = 700; i >= 0; --i)
        if(ok[i]){
            mxx = i;
            return;
        }
}

void write()
{
    ofstream fout ("cds.out");
    if(sum <= 1400 && sum-mxx <= mxx && ok[sum-mxx])
        fout << sum-mxx << " " << mxx << "\n";
    else
        fout << "0 0";
    fout.close();
}

int main()
{
    read();
    solve();
    write();
    return 0;
}

