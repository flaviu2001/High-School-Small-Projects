//Until at last, I threw down my enemy and smote his ruin upon the mountainside

#include <bits/stdc++.h>
#define verf ( (++CharB==MaxChar) ? ( fin.read(Buffer,MaxChar),CharB=0 ) : (1) )

using namespace std;
typedef long long ll;

const int M = 1000000009, B = 26, nmax = 500005, lnm = 20, MaxChar = 10000000; //maybe try 2000000011
int n, nxt[lnm][nmax], h[lnm][nmax], pwr[nmax], CharB = MaxChar - 1;
char c[nmax], Buffer[MaxChar];
vector<int> v[nmax];
ifstream fin ("parb.in");
ofstream fout ("parb.out");

void cit(int &a)
{
    bool ok = 0;
    for(;!((Buffer[CharB] >= '0' && Buffer[CharB] <= '9') || (Buffer[CharB] == '-')); verf)
        ;
    if ( Buffer[ CharB ] == '-' )
    {
        ++ CharB;
        ok = 1;
    }
    for(a = 0; (Buffer[CharB] >= '0' && Buffer[CharB] <= '9'); a *= 10, a +=(Buffer[CharB] - '0'), verf)
        ;
    if(ok)
        a = -a;
}

int compare(int x, int y)
{
    if(c[x] != c[y])
        return (c[x] >= c[y] ? x : y);
    int nx = x, ny = y;
    for (int i = lnm-1; i >= 0; --i)
        if(h[i][nx] == h[i][ny] && nxt[i][nx] != 0 && nxt[i][ny] != 0){
            nx = nxt[i][nx];
            ny = nxt[i][ny];
        }
    if(nxt[0][nx] != 0 && nxt[0][ny] != 0){
        nx = nxt[0][nx];
        ny = nxt[0][ny];
        return (c[nx] >= c[ny] ? x : y);
    }else if (nxt[0][ny] != 0)
        return y;
    else return x;
}

void construct(int x, int pred = 0)
{
    char mx = -1;
    for (auto y : v[x])
        if(y != pred){
            construct(y, x);
            mx = max(mx, c[y]);
        }
    int best = 0;
    for (auto y : v[x])
        if(y != pred && c[y] == mx)
            best = (best == 0 ? y : compare(best, y));
    nxt[0][x] = best;
    h[0][x] = (c[x]-'a')*B+c[best]-'a';
    int pw = 1;
    while(nxt[pw-1][nxt[pw-1][x]] != 0){
        nxt[pw][x] = nxt[pw-1][nxt[pw-1][x]];
        h[pw][x] = ((1ll*h[pw-1][x]*pwr[1<<pw])%M+h[pw-1][nxt[pw-1][x]])%M;
        ++pw;
    }
}

int main()
{
    fin >> n >> (c+1);
    for (int i = 2; i <= n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    pwr[0] = 1;
    for (int i = 1; i < nmax; ++i)
        pwr[i] = (1ll*pwr[i-1]*B)%M;
    construct(1);
    int best = -1;
    char mx = -1;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, c[i]);
    for (int i = 1; i <= n; ++i)
        if(c[i] == mx)
            best = (best == -1 ? i : compare(best, i));
    while(best){
        fout << c[best];
        best = nxt[0][best];
    }
    return 0;
}

