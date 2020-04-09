#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

vector< pair<int, int> > v[1005];
int home, n, m, p, t[5], r[1005], d[5][1005];
int f[] = {0, 1, 2, 3, 4};

void dijkstra(int x, int D[])
{
    set< pair<int, int> > q;
    q.insert(make_pair(0, x));
    while(!q.empty()){
        int k = q.begin()->second;
        q.erase(q.begin());
        for (vector< pair<int, int> >::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if((D[it->first] > D[k] + it->second || D[it->first] == 0) && it->first != x){
                if(D[it->first] != 0)
                    q.erase(q.find(make_pair(D[it->first], it->first)));
                D[it->first] = D[k] + it->second;
                q.insert(make_pair(D[it->first], it->first));
            }
    }
}

int main()
{
    ifstream fin ("zmeu.in");
    ofstream fout ("zmeu.out");
    fin >> n >> m >> p >> home;
    for (int i = 0; i < 5; ++i)
        fin >> t[i];
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= p; ++i)
        fin >> r[i];
    for (int i = 0; i < 5; ++i)
        dijkstra(t[i], d[i]);
    int mn = 2000000000;
    do{
        int sol = d[f[0]][home] + d[f[1]][t[f[0]]] + d[f[2]][t[f[1]]] + d[f[3]][t[f[2]]] + d[f[4]][t[f[3]]];
        int mn2 = 2000000000;
        for (int i = 1; i <= p; ++i)
            mn2 = min(mn2, d[f[4]][r[i]]);
        if(mn2 != 2000000000)
            mn = min(mn, sol+mn2);
    }while(next_permutation(f, f+5));
    fout << mn << "\n";
    fin.close();
    fout.close();
    return 0;
}

