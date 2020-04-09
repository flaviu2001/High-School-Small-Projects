#include <bits/stdc++.h>

using namespace std;

const string file = "acolor";
const int  nmax = 100005, M = 10007;

int n, r, k, pd[4][nmax], go[nmax][2], invk;

int pw(int x, int y)
{
    int p = 1;
    while(y)
        if(y%2 == 0){
            x *= x;
            x %= M;
            y /= 2;
        }else{
            p *= x;
            p %= M;
            --y;
        }
    return p;
}

void dfs(int x)
{
    int a = go[x][0], b = go[x][1];
    if(a != 0)
        dfs(a);
    if(b != 0)
        dfs(b);
    if(a+b == 0)
        pd[3][x] = 1;
    else if(min(a, b) != 0){
        int add;

        add = (pd[2][a]*pd[2][b])%M;
        add = (1ll*add*invk*invk)%M;
        add = (1ll*add*(k-2)*(k-2)*(k-2)*(k-2))%M;
        pd[2][x] = (pd[2][x]+add)%M;

        add = (pd[0][b]*pd[2][a]+pd[0][a]*pd[2][b]+pd[1][a]*pd[2][b]+pd[2][a]*pd[1][b])%M;
        add = (1ll*add*(k-2)*(k-2)*(k-2)*invk)%M;
        pd[2][x] = (pd[2][x]+add)%M;

        add = (pd[0][b]*pd[0][a]+pd[3][a]*pd[2][b]+pd[2][a]*pd[3][b]+pd[1][a]*pd[0][b]+pd[1][a]*pd[1][b]+pd[0][a]*pd[1][b])%M;
        add = (add*(k-2)*(k-2))%M;
        pd[2][x] = (pd[2][x]+add)%M;

        add = (pd[3][a]*pd[1][b]+pd[1][a]*pd[3][b]+pd[0][a]*pd[3][b]+pd[0][b]*pd[3][a])%M;
        add = (add*(k-1)*(k-2))%M;
        pd[2][x] = (pd[2][x]+add)%M;

        add = (pd[3][a]*pd[3][b])%M;
        add = (add*(k-1)*(k-1))%M;
        pd[2][x] = (pd[2][x]+add)%M;

        add = (pd[2][a]*pd[2][b])%M;
        add = (1ll*add*invk*invk)%M;
        add = (1ll*add*(k-2)*(k-2)*(k-2))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = (pd[2][a]*pd[0][b]+pd[1][a]*pd[2][b]+pd[2][a]*pd[1][b])%M;
        add = (1ll*add*(k-2)*(k-2)*invk)%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = (pd[2][a]*pd[3][b]+pd[1][a]*pd[0][b]+pd[1][a]*pd[1][b])%M;
        add = (add*(k-2))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = (pd[1][a]*pd[3][b])%M;
        add = (add*(k-1))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = (pd[2][a]*pd[2][b])%M;
        add = (1ll*add*invk*invk)%M;
        add = (1ll*add*(k-2)*(k-2)*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[0][a]*pd[2][b])%M;
        add = (1ll*add*(k-2)*(k-2)*invk)%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[1][a]*pd[2][b])%M;
        add = (1ll*add*invk*(k-2)*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[3][a]*pd[2][b])%M;
        add = (add*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[2][a]*pd[0][b])%M;
        add = (1ll*add*invk*(k-2)*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[0][a]*pd[0][b])%M;
        add = (add*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[1][a]*pd[0][b])%M;
        add = (add*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[3][a]*pd[0][b])%M;
        add = (add*(k-1))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = (pd[2][a]*pd[2][b])%M;
        add = (1ll*add*invk*invk*(k-2)*(k-2))%M;
        pd[3][x] = (pd[3][x]+add)%M;

        add = (pd[1][a]*pd[2][b]+pd[2][a]*pd[0][b])%M;
        add = (1ll*add*(k-2)*invk)%M;
        pd[3][x] = (pd[3][x]+add)%M;

        add = (pd[1][a]*pd[0][b])%M;
        pd[3][x] = (pd[3][x]+add)%M;
    }else if(b == 0){
        int add;

        add = pd[2][a];
        add = (1ll*add*invk*(k-2)*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = pd[0][a];
        add = (add*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = pd[1][a];
        add = (1ll*add*invk*(k-1)*(k-2))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = pd[3][a];
        add = (add*(k-1))%M;
        pd[1][x] = (pd[1][x]+add)%M;

        add = pd[2][a];
        add = (1ll*add*(k-2)*invk)%M;
        pd[3][x] = (pd[3][x]+add)%M;

        add = pd[1][a];
        pd[3][x] = (pd[3][x]+add)%M;

    }else{
        int add;

        add = pd[2][b];
        add = (1ll*add*(k-2)*(k-2)*invk)%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = pd[0][b];
        add = (add*(k-2))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = pd[1][b];
        add = (add*(k-2))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = pd[3][b];
        add = (add*(k-1))%M;
        pd[0][x] = (pd[0][x]+add)%M;

        add = pd[2][b];
        add = (1ll*add*(k-2)*invk)%M;
        pd[3][x] = (pd[3][x]+add)%M;

        add = pd[0][b];
        pd[3][x] = (pd[3][x]+add)%M;
    }
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> r >> k;
    invk = pw(k-1, M-2);
    for (int i = 1; i <= n; ++i)
        fin >> go[i][0] >> go[i][1];
    dfs(r);
    fout << ((pd[0][r]+pd[1][r]+pd[2][r]+pd[3][r])*k)%M << "\n";
    return 0;
}
