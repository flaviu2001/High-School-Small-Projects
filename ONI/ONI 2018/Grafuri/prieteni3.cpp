#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, a, t, d[105];
bool ok[105];
vector<int> v[105], sol;

int main()
{
    ifstream fin ("prieteni3.in");
    ofstream fout ("prieteni3.out");
    fin >> n >> a >> t;
    for (int i = 1; i <= n; ++i){
        int m;
        fin >> m;
        while(m--){
            int x;
            fin >> x;
            v[i].push_back(x);
        }
    }
    queue<int> q;
    q.push(a);
    ok[a] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(!ok[v[k][i]]){
                ok[v[k][i]] = 1;
                q.push(v[k][i]);
                d[v[k][i]] = d[k] + 1;
                if(d[v[k][i]] == t)
                    sol.push_back(v[k][i]);
            }
    }
    sort(sol.begin(), sol.end());
    fout << sol.size() << "\n";
    for (unsigned i = 0; i < sol.size(); ++i)
        fout << sol[i] << " ";
    fin.close();
    fout.close();
    return 0;
}

