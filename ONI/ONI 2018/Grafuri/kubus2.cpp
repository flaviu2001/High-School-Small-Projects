#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct coord{
    int x, y, z;
    bool operator==(coord &obj){
        return x == obj.x && y == obj.y && z == obj.z;
    }
}d1, d2;

vector<coord> tr;
vector< pair<int, int> > v[3005];
int n, fa, la, ca, fz, lz, cz, m, mn = 2000000000, xa, xz, portals = 2;

void bf(int x)
{
    int d[3005];
    for (int i = 0; i < 3005; ++i)
        d[i] = 2000000000;
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i].first] > d[k] + v[k][i].second){
                d[v[k][i].first] = d[k] + v[k][i].second;
                q.push(v[k][i].first);
            }
    }
    if(d[1] != 2000000000 && d[2] != 2000000000){
        if(mn > d[1] + d[2]){
            mn = d[1] + d[2];
            xa = d[1];
            xz = d[2];
        }else if(mn == d[1] + d[2] && d[1] < xa){
            xa = d[1];
            xz = d[2];
        }
    }
}

int main()
{
    ifstream fin ("kubus2.in");
    ofstream fout ("kubus2.out");
    fin >> n >> d1.x >> d1.y >> d1.z >> d2.x >> d2.y >> d2.z >> m;
    tr.push_back(d1);
    tr.push_back(d2);
    while(m--){
        int c;
        fin >> d1.x >> d1.y >> d1.z >> d2.x >> d2.y >> d2.z >> c;
        unsigned i1, i2;
        for (i1 = 0; i1 < tr.size(); ++i1)
            if(tr[i1] == d1)
                break;
        if(i1 == tr.size())
            tr.push_back(d1);
        ++i1;
        for (i2 = 0; i2 < tr.size(); ++i2)
            if(tr[i2] == d2)
                break;
        if(i2 == tr.size())
            tr.push_back(d2);
        ++i2;
        v[i1].push_back(make_pair(i2, c));
        v[i2].push_back(make_pair(i1, c));
    }
    n = tr.size();
    for (int i = 3; i <= n; ++i)
        bf(i);
    if(mn == 2000000000)
        fout << "-1\n";
    else
        fout << mn << "\n" << xa << " " << xz << "\n";
    fin.close();
    fout.close();
    return 0;
}

