#include <bits/stdc++.h>

using namespace std;

struct thing{
    int x, d;
    bool operator<(const thing &obj)const{
        return d < obj.d;
    }
}pd[20][400005];

int n, t, a, b, nodes[200005], euclid[400005], p, first[200005], depth[200005], lg2[400005], up[20][200005], tt[200005], sol1[200005], sol2[200005], ans;
bool ok[200005];
vector<int> v[200005];

thing make_thing (int x, int d)
{
    thing aux;
    aux.x = x;
    aux.d = d;
    return aux;
}

void build_rmq()
{
    for (int i = p; i > 0; --i){
        pd[0][i] = make_thing(euclid[i], depth[euclid[i]]);
        for (int d = 1; i+(1<<d) <= p; ++d)
            pd[d][i] = min(pd[d-1][i], pd[d-1][i+(1<<(d-1))]);
    }
}

int rmq_query(int x, int y)
{
    if(x == y)
        return x;
    if(first[x] > first[y])
        swap(x, y);
    int lg = lg2[first[y]-first[x]];
    return min(pd[lg][first[x]], pd[lg][first[y]-(1<<lg)]).x;
}

void df(int x, int pred = 0)
{
    depth[x] = depth[pred] + 1;
    tt[x] = pred;
    up[0][x] = tt[x];
    for (int d = 1; depth[x]-(1<<d)>=1; ++d)
        up[d][x] = up[d-1][up[d-1][x]];
    euclid[++p] = x;
    first[x] = p;
    vector<int>::iterator er;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(*it == pred)
            er = it;
        else{
            df(*it, x);
            euclid[++p] = x;
        }
    if(x != 1)
        v[x].erase(er);
}

int dist(int u1, int u2)
{
    int lca = rmq_query(u1, u2), d1 = 0, d2 = 0;
    while(depth[u1] > depth[lca]){
        int lg = lg2[depth[u1]-depth[lca]];
        d1 += 1<<lg;
        u1 = up[lg][u1];
    }
    while(depth[u2] > depth[lca]){
        int lg = lg2[depth[u2]-depth[lca]];
        d2 += 1<<lg;
        u2 = up[lg][u2];
    }
    return d1+d2;
}

int main()
{
    ifstream fin ("maxdist.in");
    ofstream fout ("maxdist.out");
    fin >> n >> t;
    for (int i = 2; i <= n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    df(1);
    lg2[2] = 1;
    for (int i = 3; i < 400005; ++i)
        lg2[i] = lg2[i/2]+1;
    build_rmq();

    fin >> a >> b;
    nodes[1] = a;
    nodes[2] = b;
    ans = dist(a, b);
    sol1[1] = 0;
    sol1[2] = ans;
    ok[a] = ok[b] = 1;
    for (int i = 3; i <= t; ++i){
        fin >> nodes[i];
        int u = nodes[i], u_to_a, u_to_b;
        ok[u] = 1;
        u_to_a = dist(u, a);
        u_to_b = dist(u, b);
        if(u_to_a > ans && u_to_a > u_to_b){
            b = u;
            ans = u_to_a;
        }
        if(u_to_b > ans && u_to_b > u_to_a){
            a = u;
            ans = u_to_b;
        }
        sol1[i] = ans;
    }
    a = -1, b = -1, ans = 0;
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            if(a == -1)
                a = i;
            else if (b == -1){
                b = i;
                ans = dist(a, b);
            }else{
                int u = i, u_to_a, u_to_b;
                u_to_a = dist(u, a);
                u_to_b = dist(u, b);
                if(u_to_a > ans && u_to_a > u_to_b){
                    b = u;
                    ans = u_to_a;
                }
                if(u_to_b > ans && u_to_b > u_to_a){
                    a = u;
                    ans = u_to_b;
                }
            }
        }
    sol2[t] = ans;
    for (int i = t-1; i > 0; --i){
        if(a == -1){
            a = nodes[i+1];
        }else if (b == -1){
            b = nodes[i+1];
            ans = dist(a, b);
            sol2[i] = ans;
        }else{
            int u = nodes[i+1], u_to_a, u_to_b;
            u_to_a = dist(u, a);
            u_to_b = dist(u, b);
            if(u_to_a > ans && u_to_a > u_to_b){
                b = u;
                ans = u_to_a;
            }
            if(u_to_b > ans && u_to_b > u_to_a){
                a = u;
                ans = u_to_b;
            }
            sol2[i] = ans;
        }
    }
    for (int i = 1; i <= t; ++i)
        fout << sol2[i] << " " << sol1[i] << "\n";
    fin.close();
    fout.close();
    return 0;
}

