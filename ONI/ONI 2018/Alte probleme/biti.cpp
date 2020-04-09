#include <bits/stdc++.h>

using namespace std;

ifstream fin ("biti.in");
ofstream fout ("biti.out");
int n, t, vf;
bool sol[2000000];
bool ok[2000000], gameover;

int nx1(int x)
{
    return (x*2 >= t ? x*2-t : x*2);
}

int nx2(int x)
{
    return (x*2+1 >= t ? x*2+1-t : x*2+1);
}

void bkt(int x)
{
    if(gameover)
        return;
    if(vf == t+n-1){
        gameover = true;
        fout << vf << "\n";
        for (int i = 1; i <= vf; ++i)
            fout << sol[i];
        fout << "\n";
        return;
    }
    if(!ok[nx1(x)]){
        sol[++vf] = 0;
        ok[nx1(x)] = 1;
        bkt(nx1(x));
        ok[nx1(x)] = 0;
        --vf;
        if(gameover)
            return;
    }
    if(!ok[nx2(x)]){
        sol[++vf] = 1;
        ok[nx2(x)] = 1;
        bkt(nx2(x));
        ok[nx2(x)] = 0;
        --vf;
        if(gameover)
            return;
    }
}

int main()
{
    fin >> n;
    t = (1<<n);
    vf = n;
    ok[0] = 1;
    bkt(0);
    return 0;
}

