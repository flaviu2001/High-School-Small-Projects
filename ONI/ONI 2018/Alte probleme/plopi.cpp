#include <bits/stdc++.h>

using namespace std;

struct plopi{
    long long pare, impare, comb, oricum;
}d[100005];

long long n;
vector< pair<long long, long long> > v[100005];

void df(long long x, long long pred = 0)
{
    long long par = 0, impar = 0;
    for (vector< pair<long long, long long> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(it->first != pred){
            df(it->first, x);
            if(it->second == 1){
                d[x].impare += d[it->first].pare;
                d[x].pare += d[it->first].impare;
                ++impar;
                d[x].comb -= (d[it->first].impare)*(d[it->first].pare+1);
            }else{
                d[x].impare += d[it->first].impare;
                d[x].pare += d[it->first].pare;
                ++par;
                d[x].comb -= (d[it->first].pare+1)*(d[it->first].impare);
            }
            d[x].oricum += d[it->first].oricum;
        }
    d[x].pare += par;
    d[x].impare += impar;
    d[x].comb += d[x].pare*d[x].impare;
    d[x].oricum += d[x].impare+d[x].comb;
}

int main()
{
    ifstream fin ("plopi.in");
    ofstream fout ("plopi.out");
    fin >> n;
    for (long long i = 1; i < n; ++i){
        long long x, y, z;
        fin >> x >> y >> z; z%=2;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    df(1);
    fout << d[1].oricum << "\n";
    fin.close();
    fout.close();
    return 0;
}
