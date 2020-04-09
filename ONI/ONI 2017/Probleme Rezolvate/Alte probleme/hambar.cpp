#include <cstdio>
#include <vector>

using namespace std;

struct thing{
    int x, y;
};

int n, t, mx;
vector<thing> v;

thing make_thing(int x, int y)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

bool check(int i, int lox, int loy, int hix, int hiy)
{
    return (v[i].x >= lox && v[i].x <= hix && v[i].y >= loy && v[i].y <= hiy);
}

int bin_src(int lox, int loy, int hix, int hiy)
{
    int lo = 0, hi = t-1, m;
    for (m = (lo+hi)>>1; lo <= hi; m = (lo+hi)>>1)
        if(v[m].x >= lox && v[m].x <= hix && v[m].y >= loy && v[m].y <= hiy)
            return m;
        else if(v[m].x < lox || (v[m].x == lox && v[m].y < loy))
            lo = m+1;
        else hi = m-1;
    return 0;
}

int habmar(int lox, int loy, int hix, int hiy)
{
    if(mx >= (hix-lox+1)*(hiy-loy+1))
        return 0;
    for (int i = bin_src(lox, loy, hix, hiy); i < t; ++i)
        if(check(i, lox, loy, hix, hiy))
            return max(max(habmar(lox, loy, v[i].x-1, hiy), habmar(v[i].x+1, loy, hix, hiy)), max(habmar(lox, loy, hix, v[i].y-1), habmar(lox, v[i].y+1, hix, hiy)));
    mx = max(mx, (hix-lox+1)*(hiy-loy+1));
    return (hix-lox+1)*(hiy-loy+1);
}

int main()
{
    freopen("hambar.in", "r", stdin);
    freopen("hambar.out", "w", stdout);
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= t; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(make_thing(x, y));
    }
    printf("%d\n", habmar(1, 1, n, n));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

