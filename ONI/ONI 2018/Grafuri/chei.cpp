#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<int> w;
vector<int> v[100003];
int n, ok[100003], p = 1, k, s[100003];

void bf(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(!ok[v[k][i]] || ok[v[k][i]] != p){
                ok[v[k][i]] = p;
                q.push(v[k][i]);
            }
    }
    ++p;
}

int main()
{
    ifstream fin ("chei.in");
    ofstream fout ("chei.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        v[x].push_back(i);
        s[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        if(!ok[i])
            bf(i);
    for (int i = 1; i <= n; ++i){
        if(w.find(ok[i]) == w.end()){
            w.insert(ok[i]);
            ++k;
        }
    }
    fout << k << "\n";
    fin.close();
    fout.close();
    return 0;
}

