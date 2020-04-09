#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll test, M;

ll b(ll x, ll pw)
{
    ll all = 0;
    ll nx = x-x%(pw*2);
    all += nx/2;
    if(x-nx-pw > 0)
        all += x-nx-pw;
    return all;
}

ll submatrix(ll x, ll y)
{
    ++x, ++y;
    ll ans = (x*y/2)%M, pw = 2;
    while(pw < max(x, y)){
        ll ax = x-(x%(pw*2))+pw*2;
        ll ay = y-(y%(pw*2))+pw*2;
        ll bits = ax*ay/2;
        ll rem = b(ay, pw);
        if(ax-pw > x){
            bits -= (ax-pw-x)*rem;
            bits -= pw*(ay-rem);
        }else
            bits -= (ax-x)*(ay-rem);
        rem = b(x, pw);
        if(ay-pw > y){
            bits -= (ay-pw-y)*rem;
            bits -= pw*(x-rem);
        }else
            bits -= (ay-y)*(x-rem);
        ans = (ans+(bits%M)*pw)%M;
        pw *= 2;
    }
    return ans;
}

int main()
{
    ifstream fin ("xor.in");
    ofstream fout ("xor.out");
    fin >> test >> M;
    while(test--){
        ll x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        ll show = (submatrix(x2, y2)+submatrix(x1-1, y1-1)-submatrix(x1-1, y2)-submatrix(x2, y1-1)+M+M)%M;
        fout << show << "\n";
    }
    return 0;
}

