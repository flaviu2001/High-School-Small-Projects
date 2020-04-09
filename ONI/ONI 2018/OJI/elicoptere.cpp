#include <bits/stdc++.h>

using namespace std;

struct punct{
    double x,y;
};

struct tri{
    punct A,B,C;
};

struct edge{
    double c;
    int x, y;

    bool operator<(const edge &obj)const{
        return c < obj.c;
    }
};

tri tris[105];
vector<int> v[105];
int n, m, test, pers, c[105], rng[105], cnt;
double cost;
bool ok[105];
edge g[105*105];

punct make_punct(double x, double y)
{
    punct aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

tri make_tri(punct a, punct b, punct c)
{
    tri aux;
    aux.A = a;
    aux.B = b;
    aux.C = c;
    return aux;
}

edge make_edge(double c, int x, int y)
{
    edge aux;
    aux.c = c;
    aux.x = x;
    aux.y = y;
    return aux;
}

int find(int x)
{
    int R;
    for (R = x; c[R] != R; R = c[R]);
    while(c[x] != x){
        int y = c[x];
        c[x] = R;
        x = y;
    }
    return R;
}

void unite(int x, int y)
{
    if(rng[x] > rng[y])
        c[y] = x;
    else c[x] = y;
    if(rng[x] == rng[y])
        ++rng[y];
}

double distLaturaOrizontala(punct M, punct P, punct Q){
    double a,b,c;
    punct N;
    a=Q.y-P.y;
    b=P.x-Q.x;
    c=P.y*Q.x-P.x*Q.y;
    if(P.y==M.y && M.y==Q.y)
        return min(fabs(P.x-M.x),fabs(Q.x-M.x));
    if(P.y==Q.y)
        return 1000000;
    N.y=M.y;
    N.x=(-b*M.y-c)/a;
    if((P.y<=M.y && M.y<=Q.y)||(Q.y<=M.y && M.y<=P.y))
        return sqrt((M.x-N.x)*(M.x-N.x)+(M.y-N.y)*(M.y-N.y));
    return 1000000;
}

double distLaturaVerticala(punct M, punct P, punct Q){
    double a,b,c;
    punct N;
    a=Q.y-P.y;
    b=P.x-Q.x;
    c=P.y*Q.x-P.x*Q.y;
    if(P.x==M.x && M.x==Q.x)
        return min(fabs(P.y-M.y),fabs(Q.y-M.y));
    if(P.x==Q.x)
        return 1000000;
    N.x=M.x;
    N.y=(-a*M.x-c)/b;
    if((P.x<=M.x && M.x<=Q.x)||(Q.x<=M.x && M.x<=P.x))
        return sqrt((M.x-N.x)*(M.x-N.x)+(M.y-N.y)*(M.y-N.y));
    return 1000000;
}

double distTriOrizontala(tri W, tri V){
    double Min,d;
    Min=1000000;
    d=distLaturaOrizontala(W.A,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.A,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.A,V.B,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.B,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.B,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.B,V.B,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.C,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.C,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaOrizontala(W.C,V.B,V.C);
    if(d<Min)
        Min=d;
    return Min;
}

double distTriVerticala(tri W, tri V){
    double Min,d;
    Min=1000000;
    d=distLaturaVerticala(W.A,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.A,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.A,V.B,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.B,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.B,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.B,V.B,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.C,V.A,V.B);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.C,V.A,V.C);
    if(d<Min)
        Min=d;
    d=distLaturaVerticala(W.C,V.B,V.C);
    if(d<Min)
        Min=d;
    return Min;
}

double distTri(tri x, tri y)
{
    return min(min(distTriOrizontala(x, y), distTriVerticala(x, y)), min(distTriOrizontala(y, x), distTriVerticala(y, x)));
}

void kruskal()
{
    for (int i = 0; i < 105; ++i){
        c[i] = i;
        rng[i] = 1;
    }
    sort(g+1, g+pers+1);
    for (int i = 1; i <= pers; ++i)
        if(find(g[i].x) != find(g[i].y)){
            cost += g[i].c;
            unite(find(g[i].x), find(g[i].y));
        }
}

int df(int x)
{
    ok[x] = 1;
    int p = 1;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[*it])
            p += df(*it);
    return p;
}

int main()
{
    ifstream fin ("elicoptere.in");
    ofstream fout ("elicoptere.out");
    fin >> test >> n >> m;
    for (int i = 1; i <= n; ++i){
        int x[6];
        for (int j = 0; j < 6; ++j)
            fin >> x[j];
        tris[i] = make_tri(make_punct(x[0], x[1]), make_punct(x[2], x[3]), make_punct(x[4], x[5]));
        for (int j = 1; j < i; ++j){
            double cc = distTri(tris[i], tris[j]);
            if(cc <= (double)m){
                g[++pers] = make_edge(cc, i, j);
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    int p = 0, sol2 = 0;
    for (int i = 1; i <= n;++i)
        if(!ok[i]){
            int dfs = df(i);
            sol2 += dfs*(dfs-1)/2;
            ++p;
        }
    switch(test){
        case 1:
            fout << n-p << "\n";
            break;
        case 2:
            fout << sol2 << "\n";
            break;
        case 3:
            kruskal();
            fout << fixed << setprecision(7) << cost << "\n";
            break;
    }
    fin.close();
    fout.close();
    return 0;
}

