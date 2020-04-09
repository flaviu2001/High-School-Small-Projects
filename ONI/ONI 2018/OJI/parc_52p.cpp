#include <bits/stdc++.h>

using namespace std;

struct point{
    int x = 0, y = 0;
    bool operator<(const point &obj)const{
        if(x != obj.x)
            return x < obj.x;
        return y < obj.y;
    }
};

int n, m;
point s, f; //s - start, f - finish
vector<point> horiz, vert;

point make_point(int x, int y)
{
    point aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

int main()
{
    ifstream fin ("parc.in");
    ofstream fout ("parc.out");
    fin >> n >> m >> s.x >> s.y >> f.x >> f.y;
    int sz;
    fin >> sz;
    for (int i = 1; i <= sz; ++i){
        int x, y;
        fin >> x >> y;
        if(x > y)
            swap(x, y);
        vert.push_back(make_point(x, y));
    }
    fin >> sz;
    for (int i = 1; i <= sz; ++i){
        int x, y;
        fin >> x >> y;
        if(x > y)
            swap(x, y);
        horiz.push_back(make_point(x, y));
    }
    sort(horiz.begin(), horiz.end());
    sort(vert.begin(), vert.end());

    if(s.x > f.x)
        swap(s, f);
    int skipx = 0, x = s.x, inx = 0;
    bool good = true;
    for (int i = 0; i < vert.size(); ++i)
        if(vert[i].y <= f.x && vert[i].x >= s.x){
            inx = i;
            break;
        }else if (vert[i].x >= f.x){
            good = false;
            break;
        }
    if(good)
        while(x <= f.x){
            if(inx >= vert.size() || vert[inx].x >= f.x)
                break;
            x = vert[inx].y;
            skipx += vert[inx].y-vert[inx].x;
            ++inx;
        }

    if(s.y > f.y)
        swap(s, f);
    int skipy = 0, y = s.y, iny = 0;
    good = true;
    for (int i = 0; i < horiz.size(); ++i)
        if(horiz[i].y <= f.y && horiz[i].x >= s.y){
            iny = i;
            break;
        }else if (horiz[i].x >= f.y){
            good = false;
            break;
        }
    if(good)
        while(y <= f.y){
            if(iny >= horiz.size() || horiz[iny].x >= f.y)
                break;
            y = horiz[iny].y;
            skipy += horiz[iny].y-horiz[iny].x;
            ++iny;
        }

    int ugly = (max(s.x, f.x)-min(s.x, f.x)-skipx)*(max(s.x, f.x)-min(s.x, f.x)-skipx) + (max(s.y, f.y)-min(s.y, f.y)-skipy)*(max(s.y, f.y)-min(s.y, f.y)-skipy);
    float ans = skipx + skipy + sqrt(ugly);
    if(ans != (int) ans)
        fout << fixed << setprecision(6) << ans << "\n1\n";
    else fout << ans << "\n1\n";
    fin.close();
    fout.close();
    return 0;
}

