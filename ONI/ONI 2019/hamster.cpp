#include <bits/stdc++.h>

using namespace std;

const int BUF_SIZE = 1 << 17;
int pos = BUF_SIZE, out = 0;
char buf[BUF_SIZE], Out[BUF_SIZE], str[10];
FILE *f, *OUT;
inline char nextch(){
    if(pos==BUF_SIZE) fread(buf, BUF_SIZE, 1, f), pos=0;
    return buf[pos++];
}
inline long long read(){
    long long x=0;
    char ch=nextch();
    while(!isdigit(ch)) ch=nextch();
    while(isdigit(ch)){
        x=10*x+ch-'0';
        ch=nextch();
    }
    return x;
}

inline void Write_Ch(char ch)
{
    Out[out++]=ch;
    if(out==BUF_SIZE)
        fwrite(Out,BUF_SIZE,1,OUT),out=0;
}
inline void Write_Int(int nr)
{
    int x=0;
    do
    {
        str[x++]=nr%10+'0';
        nr/=10;
    }
    while(nr);
    while(x>0)
        Write_Ch(str[--x]);
}

typedef long long ll;
ll n, test, v[3005], pd[3005][3005];

inline ll max (ll x, ll y)
{
    return (x > y ? x : y);
}

int main()
{
    f = fopen("hamster.in", "r");
    OUT = fopen("hamster.out", "w");
    n = read();
    test = read();
    for (int i = 1; i <= n; ++i)
        v[i] = read();
    memset(pd, -1, sizeof(pd));
    for (int i = 1; i <= n; ++i){
        pd[i][1] = v[i]-v[1];
        pd[i][i] = 0;
    }
    for (int i = 2; i <= n; ++i){
        ll k = 2;
        for (int j = 2; j < i; ++j){
            while(k < i && max(v[i]-v[k], pd[k-1][j-1]) > max(v[i]-v[k+1], pd[k][j-1]))
                ++k;
            pd[i][j] = max(v[i]-v[k], pd[k-1][j-1]);
        }
    }
    ll ans, lo, hi, m, k, c;
    while(test--){
        k = read();
        c = read();
        ans = 1, lo = 1, hi = k;
        for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
            if(pd[k][m] <= c){
                hi = m-1;
                ans = m;
            }else lo = m+1;
        Write_Int(ans);
        Write_Ch('\n');
    }
    if(out>0)fwrite(Out,1,out,OUT);
    return 0;
}

