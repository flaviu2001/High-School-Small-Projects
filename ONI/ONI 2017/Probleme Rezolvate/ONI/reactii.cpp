#include <fstream>

using namespace std;

struct interval{
    int mn, mx, st, dr;
}aux;

interval v[15005];
int n;

bool check(interval x1, interval x2)
{
    if(x1.mx+1 == x2.mn)
        return true;
    if(x2.mx+1 == x1.mn)
        return true;
    return false;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

bool this_is_where_the_fun_begins()
{
    bool ok[15005] = {0};
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            ok[i] = 1;
            interval now = v[i];
            while(check(now, v[now.st-1]) || check(now, v[now.dr+1])){
                if(check(now, v[now.st-1])){
                    now.mn = min(now.mn, v[now.st-1].mn);
                    now.mx = max(now.mx, v[now.st-1].mx);
                    now.st = v[now.st-1].st;
                    v[now.st] = now;
                    v[now.dr] = now;
                }
                if(check(now, v[now.dr+1])){
                    now.mn = min(now.mn, v[now.dr+1].mn);
                    now.mx = max(now.mx, v[now.dr+1].mx);
                    now.dr = v[now.dr+1].dr;
                    v[now.st] = now;
                    v[now.dr] = now;
                }
            }
        }
    printf("%d %d %d %d\n", v[1].mn, v[1].mx, v[n].mn, v[n].mx);
    if(v[1].mn == 1 && v[1].mx == n)
        return true;
    if(v[n].mn == 1 && v[n].mx == n)
        return true;
    return false;
}

int main()
{
    ifstream fin ("reactii.in");
    ofstream fout ("reactii.out");
    int m;
    fin >> n >> m;
    while(m--){
        v[0].mx = 999999999;
        v[0].mn = 999999999;
        v[0].st = 0;
        v[0].dr = 0;
        v[n+1].mn = 999999999;
        v[n+1].mx = 999999999;
        v[n+1].st = n+1;
        v[n+1].dr = n+1;
        for (int i = 1; i <= n; ++i){
            int x;
            fin >> x;
            aux.st = i;
            aux.dr = i;
            aux.mn = x;
            aux.mx = x;
            v[i] = aux;
        }
        fout << this_is_where_the_fun_begins() << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
