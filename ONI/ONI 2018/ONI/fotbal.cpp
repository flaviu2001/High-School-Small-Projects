#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin ("fotbal1.in");
ofstream fout ("fotbal1.out");
vector<int> v[100006];
int n, m, from[100006], to[100006], win[100006];
bool noteuclid, ok[100006], ok2[100006];

void solve1()
{
    fout << "0\n";
    stack<int> q;
    for (int i = 1; i <= n; ++i)
        if(!ok2[i]){
            q.push(i);
            while(!q.empty()){
                int k = q.top();
                ok2[k] = 1;
                if(v[k].size() == 0){
                    q.pop();
                }else{
                    int e = v[k].back();
                    v[k].pop_back();
                    if(!ok[e]){
                        ok[e] = 1;
                        q.push(from[e] ^ to[e] ^ k);
                        win[e] = from[e] ^ to[e] ^ k;
                    }
                }
            }
        }
    for(int i = 0; i < m; ++i)
        fout << win[i] << "\n";
}

void solve2()
{
    fout << "2\n";
    int ogm = m;
    for (int i = 1; i <= n; ++i)
        if(v[i].size()%2 == 1){
            v[0].push_back(m);
            v[i].push_back(m);
            from[m] = 0;
            to[m] = i;
            ++m;
        }
    stack<int> q;
    for (int i = 1; i <= n; ++i)
        if(!ok2[i]){
            q.push(i);
            while(!q.empty()){
                int k = q.top();
                ok2[k] = 1;
                if(v[k].size() == 0){
                    q.pop();
                }else{
                    int e = v[k].back();
                    v[k].pop_back();
                    if(!ok[e]){
                        ok[e] = 1;
                        q.push(from[e] ^ to[e] ^ k);
                        win[e] = from[e] ^ to[e] ^ k;
                    }
                }
            }
        }
    for (int i = 0; i < ogm; ++i)
        fout << win[i] << "\n";
}

int main()
{
    fin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        fin >> x >> y;
        from[i] = x;
        to[i] = y;
        v[x].push_back(i);
        v[y].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].size()%2 == 1){
            noteuclid = 1;
            break;
        }
    if(!noteuclid)
        solve1();
    else solve2();
    fin.close();
    fout.close();
    return 0;
}

