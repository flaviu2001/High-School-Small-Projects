#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 200005;

int n, m, test, p[nmax], v[nmax], last[nmax], pred[20][nmax], needs[nmax], pred2[nmax], aint[nmax*4];

void build(int nod, int st, int dr)
{
    if(st == dr)
        aint[nod] = pred2[st];
    else{
        int mid = (st+dr)/2;
        build(nod*2, st, mid);
        build(nod*2+1, mid+1, dr);
        aint[nod] = max(aint[nod*2], aint[nod*2+1]);
    }
}

int query(int nod, int st, int dr, int l, int r)
{
    if(st >= l && dr <= r)
        return aint[nod];
    int mid = (st+dr)/2, ans = 0;
    if(mid >= l)
        ans = query(nod*2, st, mid, l, r);
    if(mid+1 <= r)
        ans = max(ans, query(nod*2+1, mid+1, dr, l, r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> m >> n >> test;
    for (int i = 1; i <= m; ++i)
        cin >> p[i];
    needs[p[1]] = p[m];
    for (int i = 2; i <= m; ++i)
        needs[p[i]] = p[i-1];
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i){
        last[v[i]] = i;
        pred[0][i] = last[needs[v[i]]];
    }
    int p=0;
    for (int t = 1; t <= 20; ++t)
        for (int i = (1<<t)+1; i <= n; ++i)
            pred[t][i] = pred[t-1][pred[t-1][i]];
    int x = m-1;
    while((1<<(p+1)) <= x)
        ++p;
    for (int i = 1; i <= n; ++i)
        pred2[i] = pred[p][i];
    x -= (1<<p);
    --p;
    while(p >= 0){
        if(x >= (1<<p)){
            for (int i = 1; i <= n; ++i)
                pred2[i] = pred[p][pred2[i]];
            x -= (1<<p);
        }
        --p;
    }
    build(1, 1, n);
    while(test--){
        int a, b;
        cin >> a >> b;
        if(query(1, 1, n, a, b) >= a)
            cout << 1;
        else cout << 0;
    }
    return 0;
}