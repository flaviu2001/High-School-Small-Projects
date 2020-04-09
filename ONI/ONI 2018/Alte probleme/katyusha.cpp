#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

struct line{
    ld x1, y1, x2, y2;
    ll c;
};

struct circle{
    ld x, y, r;
};

struct event{
    ld t, c;
    bool type;
    bool operator<(const event &obj)const{
        if(t != obj.t)
            return t < obj.t;
        return type < obj.type;
    }
};

bool good;
ll n, test;
line v[300005];

event make_event(ld t, ld c, bool type)
{
    event aux;
    aux.t = t;
    aux.c = c;
    aux.type = type;
    return aux;
}

ll sgn(ld x)
{
    if(x >= 0)
        return 1;
    return -1;
}

ld modul(ld x)
{
    return (x >= 0 ? x : -x);
}

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

pair<ld, ld> cross(line a, circle b)
{
    good = true;
    ld transx = b.x, transy = b.y;
    ld x1 = a.x1 - b.x;
    ld y1 = a.y1 - b.y;
    ld x2 = a.x2 - b.x;
    ld y2 = a.y2 - b.y;
    ld r = b.r;
    ld dx = x2-x1;
    ld dy = y2-y1;
    ld dr = dx*dx+dy*dy;
    ld d = x1*y2-x2*y1;
    if(r*r*dr-d*d < 0){
        good = false;
        return {0, 0};
    }
    ld ansx1 = (d*dy - sgn(dy)*dx*sqrt(r*r*dr-d*d))/(dr)+transx;
    ld ansy1 = (-d*dx - modul(dy)*sqrt(r*r*dr-d*d))/(dr)+transy;
    ld ansx2 = (d*dy + sgn(dy)*dx*sqrt(r*r*dr-d*d))/(dr)+transx;
    ld ansy2 = (-d*dx + modul(dy)*sqrt(r*r*dr-d*d))/(dr)+transy;
    if(a.x1 == a.x2){
        if(a.y1 < a.y2){
            if(ansy2 < ansy1){
                swap(ansx1, ansx2);
                swap(ansy1, ansy2);
            }
            if(ansy2 < a.y1){
                good = false;
                return {0, 0};
            }
        }else{
            if(ansy2 > ansy1){
                swap(ansx1, ansx2);
                swap(ansy1, ansy2);
            }
            if(ansy2 > a.y1){
                good = false;
                return {0, 0};
            }
        }
        ld iesire = (ansy2-a.y1)/(a.y2-a.y1);
        if(r*r*dr-d*d == 0)
            return {iesire, iesire};
        ld intrare;
        if(dist(a.x1, a.y1, b.x, b.y) <= b.r)
            intrare = 0;
        else intrare = (ansy1-a.y1)/(a.y2-a.y1);
        return {intrare, iesire};
    }
    if(a.x1 < a.x2){
        if(ansx2 < ansx1){
            swap(ansx1, ansx2);
            swap(ansy1, ansy2);
        }
        if(ansx2 < a.x1){
            good = false;
            return {0, 0};
        }
    }else{
        if(ansx2 > ansx1){
            swap(ansx1, ansx2);
            swap(ansy1, ansy2);
        }
        if(ansx2 > a.x1){
            good = false;
            return {0, 0};
        }
    }
    ld iesire = (ansx2-a.x1)/(a.x2-a.x1);
    if(r*r*dr-d*d == 0)
        return {iesire, iesire};
    ld intrare;
    if(dist(a.x1, a.y1, b.x, b.y) <= b.r)
        intrare = 0;
    else intrare = (ansx1-a.x1)/(a.x2-a.x1);
    return {intrare, iesire};
}

int main()
{
    ifstream fin ("katyusha.in");
    ofstream fout ("katyusha.out");
    fin >> n >> test;
    for (int i = 1; i <= n; ++i)
        fin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2 >> v[i].c;
    while(test--){
        circle c;
        fin >> c.x >> c.y >> c.r;
        vector<event> r;
        ll sum = 0, mx = 0;
        for (int i = 1; i <= n; ++i){
            if(v[i].x1 == v[i].x2 && v[i].y1 == v[i].y2){
                if(sqrt((c.x-v[i].x1)*(c.x-v[i].x1)+(c.y-v[i].y1)*(c.y-v[i].y1)) <= c.r)
                    sum += v[i].c;
                continue;
            }
            pair<ld, ld> ev = cross(v[i], c);
            if(good){
                r.push_back(make_event(ev.first, v[i].c, 0));
                r.push_back(make_event(ev.second, v[i].c, 1));
            }
        }
        mx = sum;
        sort(r.begin(), r.end());
        for (vector<event>::iterator it = r.begin(); it != r.end(); ++it)
            if(it->type == 0){
                sum += it->c;
                mx = max(mx, sum);
            }else
                sum -= it->c;
        fout << mx << "\n";
    }
    return 0;
}

