#include <bits/stdc++.h>

using namespace std;

struct thing{
    int c, p;
};

int n, h, b[2][100005], price[105], pages[105], copies[105];
vector<thing> v;

thing make_thing(int c, int p)
{
    thing aux;
    aux.c = c;
    aux.p = p;
    return aux;
}

int main()
{
    //ifstream cin ("data.in");
    cin >> n >> h;
    for (int i = 1; i <= n; ++i)
        cin >> price[i];
    for (int i = 1; i <= n; ++i)
        cin >> pages[i];
    for (int i = 1; i <= n; ++i)
        cin >> copies[i];
    for (int i = 1; i <= n; ++i){
        int x=price[i], y=pages[i], z=copies[i], sum = 0;
        if(x*z > h)
            z = h/x;
        for (int i = 1; 1; i *= 2){
            if(sum+i > z)
                break;
            sum += i;
            v.push_back(make_thing(x*i, y*i));
        }
        if(z-sum > 0)
            v.push_back(make_thing(x*(z-sum), y*(z-sum)));
    }
    for (int i = 0; i < v.size(); ++i){
        int c = v[i].c, p = v[i].p;
        for (int j = 0; j < c; ++j)
            b[i%2][j] = b[(1-(i%2))][j];
        for (int j = c; j <= h; ++j)
            b[i%2][j] = max(b[1-(i%2)][j], b[1-(i%2)][j-c]+p);
    }
    int sol = 0;
    for (int j = 0; j <= h; ++j)
        sol = max(sol, b[(v.size()-1)%2][j]);
    cout << sol;
    return 0;
}

