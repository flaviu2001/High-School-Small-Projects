#include <bits/stdc++.h>

using namespace std;

struct query{
    int x1, y1, x2, y2, i;
    int st, dr, m, ans;
    bool operator<(const query &obj)const{
        return m > obj.m;
    }
};

struct elem{
    int x, y, val;
    bool operator< (const elem &obj)const{
        return val >= obj.val;
    }
};

const int nmax = 305, hmax = 1000000, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, answered, c[nmax*nmax+5], rng[nmax*nmax+5], v[nmax][nmax], sol[20005];
vector<query> q;
vector<elem> e;

query make_query(int x1, int y1, int x2, int y2, int i, int st = 1, int dr = hmax, int m = hmax/2, int ans = 1)
{
    query aux;
    aux.x1 = x1;
    aux.y1 = y1;
    aux.x2 = x2;
    aux.y2 = y2;
    aux.i = i;
    aux.st = st;
    aux.dr = dr;
    aux.m = m;
    aux.ans = ans;
    return aux;
}

elem make_elem(int x, int y, int val)
{
    elem aux;
    aux.x = x;
    aux.y = y;
    aux.val = val;
    return aux;
}

int find(int x)
{
    if(x == c[x])
        return x;
    c[x] = find(c[x]);
    return c[x];
}

void unite(int x, int y)
{
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

bool check(int x, int y, int val)
{
    return x > 0 && y > 0 && x <= n && y <= n && v[x][y] >= val;
}

int main()
{
    ifstream fin ("matrice2.in");
    ofstream fout ("matrice2.out");
    fin >> n >> m;
    int nrmin = 2000000000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            int x;
            fin >> x;
            v[i][j] = x;
            nrmin = min(nrmin, x);
            e.push_back(make_elem(i, j, x));
        }
    sort(e.begin(), e.end());
    for (int i = 1; i <= m; ++i){
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        q.push_back(make_query(x1, y1, x2, y2, i));
    }
    int cont = 1;
    while(answered < m && cont <= 30){
        for (int i = 1; i <= nmax*nmax; ++i){
            c[i] = i;
            rng[i] = 1;
        }
        sort(q.begin(), q.end());
        unsigned p = 0;
        for (vector<elem>::iterator it = e.begin(); it != e.end(); ++it){
            for (int i = 0; i < 4; ++i)
                if(check(it->x+dx[i], it->y+dy[i], v[it->x][it->y]))
                    unite(find(it->x*nmax+it->y), find((it->x+dx[i])*nmax+it->y+dy[i]));
            if(it+1 == e.end() || it->val > (it+1)->val){
                int x = it->val;
                while(q[p].m >= x && p < q.size()){
                    if(q[p].st > q[p].dr){
                        ++p;
                        continue;
                    }
                    if(find(q[p].x1*nmax+q[p].y1) == find(q[p].x2*nmax+q[p].y2)){
                        q[p].ans = x;
                        q[p].st = q[p].m+1;
                    }else
                        q[p].dr = q[p].m-1;
                    q[p].m = (q[p].st+q[p].dr)/2;
                    if(q[p].st > q[p].dr){
                        ++answered;
                        sol[q[p].i] = q[p].ans;
                    }
                    ++p;
                }
            }
        }
        ++cont;
    }
    for (int i = 1; i <= m; ++i)
        fout << max(sol[i], nrmin) << "\n";
    return 0;
}

