#include <cstdio>
#include <vector>
#include <queue>

#define MAX 100005
#define INF 9223372036854775807
#define pp pair <int, int>
#define ppl pair <long long, int>
#define ff first
#define ss second
#define ll long long

using namespace std;

vector<pp> v[MAX];
int n, m, a, b, c, pa[MAX], pb[MAX], pc[MAX], sol[MAX];
ll da[MAX], db[MAX], dc[MAX];

void read();
void dijkstra(int nod, long long d[], int p[]);
void write();

int main(){
    read();
    dijkstra(a, da, pa);
    dijkstra(b, db, pb);
    dijkstra(c, dc, pc);
    write();
    return 0;
}

void read(){
    freopen ("trilant.in", "r", stdin);
    scanf ("%d%d%d%d%d", &n, &m, &a, &b, &c);
    int x, y ,z;
    while(m--){
        scanf ("%d%d%d", &x, &y, &z);
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    fclose(stdin);
}

void dijkstra(int nod, ll d[], int p[]){
    priority_queue<ppl> q;
    for (int i = 1; i <= n; ++i)
        d[i] = INF;
    d[nod] = 0;
    p[nod] = -1;
    q.push(make_pair(0, nod));
    while(!q.empty()){
        int k = q.top().ss;
        ll c = -q.top().ff;
        q.pop();
        for (unsigned int i = 0; i < v[k].size(); ++i)
            if (d[v[k][i].ff] > c + v[k][i].ss)
                d[v[k][i].ff] = c + v[k][i].ss,
                p[v[k][i].ff] = k,
                q.push(make_pair(-d[v[k][i].ff], v[k][i].ff));
    }
}

void write(){
    freopen ("trilant.out", "w", stdout);
    long long mn = da[1] + db[1] + dc[1], sum;
    int I(1);
    for (int i = 2; i <= n; ++i){
        sum = da[i] + db[i] + dc[i];
        if (sum < mn)
            mn = sum,
            I = i;
    }
    printf ("%lld", mn);
    int i, j;

    j = I, i = 0;
    while(j!=pa[a]){
        sol[++i] = j;
        j = pa[j];
    }
    printf ("\n%d", i);
    for (int k = 1; k <= i; ++k)
        printf (" %d", sol[k]);

    j = I, i = 0;
    while(j!=pb[b]){
        sol[++i] = j;
        j = pb[j];
    }
    printf ("\n%d", i);
    for (int k = 1; k <= i; ++k)
        printf (" %d", sol[k]);

    j = I, i = 0;
    while(j!=pc[c]){
        sol[++i] = j;
        j = pc[j];
    }
    printf ("\n%d", i);
    for (int k = 1; k <= i; ++k)
        printf (" %d", sol[k]);

    fclose(stdout);
}
