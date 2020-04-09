#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > v[505];
int n, m, t;

int bf(int x)
{
    int d[505];
    for (int i = 0; i < 505; ++i)
        d[i] = 2000000000;
    queue<int> q;
    q.push(x);
    d[x] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(d[v[k][i].first] > d[k] + v[k][i].second){
                d[v[k][i].first] = d[k] + v[k][i].second;
                q.push(v[k][i].first);
            }
    }
    int mx = d[1];
    if(x == 1)
        mx = d[2];
    for (int i = 2; i <= n; ++i){
        if(x != i && mx < d[i])
            mx = d[i];
        if(x != i && d[i] == 2000000000)
            return 2000000000;
    }
    return mx;
}

int main()
{
    ifstream fin ("razboi.in");
    ofstream fout ("razboi.out");
    fin >> n >> m;
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[y].push_back(make_pair(x, z));
    }
    fin >> t;
    int case_t, mn = 2000000000, I;
    for (int i = 1; i <= n; ++i){
        int p = bf(i);
        if(t == i)
            case_t = p;
        if(p < mn){
            mn = p;
            I = i;
        }
    }
    if(case_t == 2000000000)
        case_t = 0;
    if(mn == 2000000000)
        mn = 0;
    if(mn != 0)
        fout << case_t << "\n" << I << " " << mn << "\n";
    else fout << "0\n0\n";
    fin.close();
    fout.close();
    return 0;
}

