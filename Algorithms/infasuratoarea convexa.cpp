#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
int n, vf;
pair<ld, ld> sj = {2000000000, 2000000000};

struct point{
    ld x, y;
    bool operator<(const point &obj)const{
        return (y-sj.second)*(obj.x-sj.first) > (x-sj.first)*(obj.y-sj.second);
    }
} v[120005], s[120005];

point make_point(ld x, ld y)
{
    point aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

bool rightTurn(point p1, point p2, point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) <= 0;
}

int main()
{
    ifstream fin ("infasuratoare.in");
    ofstream fout ("infasuratoare.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i].x >> v[i].y;
        if((sj.first > v[i].x) || (sj.first == v[i].x && sj.second > v[i].y)){
            sj.first = v[i].x;
            sj.second = v[i].y;
        }
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].x == sj.first && v[i].y == sj.second){
            for (int j = i; j < n; ++j)
                v[j] = v[j+1];
            break;
        }
    --n;
    sort(v+1, v+n+1);
    s[++vf] = make_point(sj.first, sj.second);
    s[++vf] = v[1];
    for (int i = 2; i <= n; ++i){
        while(vf >= 2 && !rightTurn(s[vf-1], s[vf], v[i]))
            --vf;
        s[++vf] = v[i];
    }
    fout << vf << "\n";
    for (int i = vf; i > 0; --i)
        fout << fixed << setprecision(10) << s[i].x << " " << s[i].y << "\n";
    return 0;
}

