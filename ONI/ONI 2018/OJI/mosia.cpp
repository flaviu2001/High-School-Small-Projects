#include <bits/stdc++.h>

using namespace std;

struct point{
    long double x, y, d;
    bool operator<(const point &obj)const;
};

typedef long double ld;
const int inf = 2000000000;
int n, vf;
ld sjx=inf, sjy=inf, sjd, sol[1005], sol2[1005];
point v[1005], s[1005];

bool point::operator<(const point &obj)const{
    if((y-sjy)*(obj.x-sjx) == (x-sjx)*(obj.y-sjy)){
        if(x==obj.x && x == sjx){
            if(y > sjy)
                return y < obj.y;
            else return y > obj.y;
        }
        if(y == obj.y && y == sjy){
            return x > obj.x;
        }
        if((y-sjy)*(obj.x-sjx) >= 0){
            if(x != obj.x)
                return x < obj.x;
            return y < obj.y;
        }else{
            if(x != obj.x)
                return x > obj.x;
            return y > obj.y;
        }
    }
    return (y-sjy)*(obj.x-sjx) > (x-sjx)*(obj.y-sjy);
}

point make_point(ld x, ld y, ld d = 0)
{
    point aux;
    aux.x = x;
    aux.y = y;
    aux.d = d;
    return aux;
}

bool rightTurn(point p1, point p2, point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) <= 0;
}

int main()
{
    ifstream fin ("mosia.in");
    ofstream fout ("mosia.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i].x >> v[i].y >> v[i].d;
        if(sjx > v[i].x || (sjx == v[i].x && sjy > v[i].y)){
            sjx = v[i].x;
            sjy = v[i].y;
            sjd = v[i].d;
        }
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].x == sjx && v[i].y == sjy){
            for (int j = i; j < n; ++j)
                v[j] = v[j+1];
            break;
        }
    --n;
    sort(v+1, v+n+1);
    s[++vf] = make_point(sjx, sjy, sjd);
    s[++vf] = v[1];
    for (int i = 2; i <= n; ++i){
        while(vf >= 2 && !rightTurn(s[vf-1], s[vf], v[i]))
            --vf;
        s[++vf] = v[i];
    }
    n = vf;
    for (int i = 1; i <= n; ++i)
        v[i] = s[i];
    reverse(v+1, v+n+1);
    v[1].d = v[1].d * sqrt((v[2].x-v[n].x)*(v[2].x-v[n].x)+(v[2].y-v[n].y)*(v[2].y-v[n].y))/2;
    v[n].d = v[n].d * sqrt((v[n-1].x-v[1].x)*(v[n-1].x-v[1].x)+(v[n-1].y-v[1].y)*(v[n-1].y-v[1].y))/2;
    for (int i = 2; i < n; ++i)
        v[i].d = v[i].d * sqrt((v[i-1].x-v[i+1].x)*(v[i-1].x-v[i+1].x)+(v[i-1].y-v[i+1].y)*(v[i-1].y-v[i+1].y))/2;
    ld ans = 0;
    for (int i = 1; i < n; ++i){
        sol[i] = v[i].d;
        ld mx = 0;
        for (int j = i-2; j >= 1; --j)
            mx = max(mx, sol[j]);
        sol[i] += mx;
        ans = max(ans, sol[i]);
    }
    for (int i = 2; i <= n; ++i){
        sol2[i] = v[i].d;
        ld mx = 0;
        for (int j = i-2; j > 1; --j)
            mx = max(mx, sol2[j]);
        sol2[i] += mx;
        ans = max(ans, sol2[i]);
    }
    fout << fixed << setprecision(10) << ans;
    return 0;
}

