#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

int n, pd[4][100005], cnt[4][100005];
bool ok[100005];
vector<int> v[100005];

void gcd(int &x, int &y, int a, int b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd(x, y, b, a%b);
        int aux = x;
        x = y;
        y = aux - y * (a/b);
    }
}

int invers_modular(int a, int b)
{
    int x, y;
    gcd(x, y, a, b);
    if(x < 0)
        x = b + x%b;
    return x;
}


void df(int x, int pred)
{
    ok[x] = 1;
    bool ye = false;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[*it]){
            ye = true;
            df(*it, x);
        }
    if(!ye){
        pd[0][x] = 0; cnt[0][x] = 1;
        pd[1][x] = 1; cnt[1][x] = 1;
        pd[2][x] = 1; cnt[2][x] = 1;
        pd[3][x] = 1; cnt[3][x] = 1;
    }else{
        int sol = 0, c = 1;
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if((*it) != pred){
                sol += pd[3][*it];
                c = ( 1LL * c * cnt[3][*it] )%M;
            }
        cnt[0][x] = c;
        pd[0][x] = sol;

        sol = 1;
        int mx = -2000000000, sum = 0, c1 = 1;
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred){
                sum += pd[0][*it];
                c1 = (1LL*c1*cnt[0][*it])%M;
                mx = max(mx, pd[2][*it]-pd[0][*it]);
            }
        sol = mx+sum;
        pd[1][x] = sol;

        c = 0;
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred && pd[2][*it]-pd[0][*it] == mx)
                c = (c + ( 1LL*(( 1LL * c1 * invers_modular( cnt[0][*it], M) ) % M) * cnt[2][*it]))%M;
        cnt[1][x] = c;

        sol = 1; c = 1;
        for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
            if(*it != pred){
                sol += pd[0][*it];
                c = ( 1LL * c * cnt[0][*it] )%M;
            }
        pd[2][x] = sol;
        cnt[2][x] = c;

        pd[3][x] = max(pd[0][x], max(pd[1][x], pd[2][x]));
        cnt[3][x] = 0;
        for (int i = 0; i < 3; ++i)
            if(pd[i][x] == pd[3][x])
                cnt[3][x] = (cnt[3][x] + cnt[i][x])%M;
    }
}

int main()
{
    ifstream fin ("arbore7.in");
    ofstream fout ("arbore7.out");
    fin >> n;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    df(1, 0);
    fout << pd[3][1] << " " << cnt[3][1] << "\n";
    fin.close();
    fout.close();
    return 0;
}

