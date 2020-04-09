#include <cstdio>
#include <vector>
#include <queue>
#define MAX 50005
#define INF 1<<30
 
using namespace std;
 
struct data{
    int edge, weight;
} nd;
 
vector<data> v[MAX];
queue<int> q;
 
int n, m, d[MAX], f[MAX];
int test, initial_point;
 
bool bell(){
    d[initial_point] = 0;
    q.push(initial_point);
 
    while(!q.empty()){
        int k = q.front();
        for (unsigned int i = 0; i < v[k].size(); ++i)
            if (d[v[k][i].edge] > d[k] + v[k][i].weight)
                d[v[k][i].edge] = d[k] + v[k][i].weight,
                q.push(v[k][i].edge);
        q.pop();
    }
 
    for (int i = 1; i <= n; ++i)
        if (d[i] != f[i])
            return false;
 
    return true;
}
 
int main(){
    freopen ("distante.in", "r", stdin);
    freopen ("distante.out", "w", stdout);
    scanf ("%d", &test);
    while(test--){
        scanf ("%d%d%d", &n, &m, &initial_point);
        for (int i = 1; i <= n; ++i)
            scanf ("%d", &f[i]),
            v[i].clear();
 
        for (int i = 1; i <= m; ++i){
            int x, y, z;
            scanf ("%d%d%d", &x, &y, &z);
            nd.edge = y, nd.weight = z;
            v[x].push_back(nd);
            nd.edge = x;
            v[y].push_back(nd);
        }
 
        for (int i = 1; i <= n; ++i)
            d[i] = INF;
 
        printf ("%s\n", (bell() ? "DA" : "NU"));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}