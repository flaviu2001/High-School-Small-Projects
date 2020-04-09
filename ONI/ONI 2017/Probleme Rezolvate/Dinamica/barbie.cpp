#include <fstream>
#include <vector>

using namespace std;

vector< pair<int, int> > v;
int g, n, c[10005];

void read()
{
    ifstream fin ("barbie.in");
    int x, y;
    fin >> x >> y >> n;
    g = y-x;
    for (int i = 0; i < n; ++i){
        fin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    fin.close();
}

int patchesThePirate(int x)
{
    if(c[x] != 0)
        return c[x];
    if(x <= 0)
        return 0;
    int mn = 1 << 30;
    for (int i = 0; i < n; ++i)
        if(x >= v[i].second){
            int e = patchesThePirate(x-v[i].second) + v[i].first;
            if(e < mn)
                mn = e;
        }
    c[x] = mn;
    return mn;
}

void write()
{
    ofstream fout ("barbie.out");
    fout << patchesThePirate(g) << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
