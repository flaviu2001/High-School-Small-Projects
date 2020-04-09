//Well, if it isn't fat stinking billy goat Billy Boy in poison! How art thou, thou globby bottle of cheap, stinking chip oil?
//Come and get one in the yarbles, if ya have any yarbles, you eunuch jelly thou!
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll divs[7000];
ll pd[4200][4200], p, n, test, guy;
unordered_map<ll, int> m;

int main()
{
    ifstream fin ("desc.in");
    ofstream fout ("desc.out");
    fin >> n >> test;
    for (ll i = 2; i*i <= n; ++i)
        if(n%i == 0){
            divs[++p] = i;
            ++guy;
            if(i*i != n)
                divs[++p] = n/i;
        }
    sort(divs+1, divs+p+1);
    divs[++p] = n;
    for (int i = 1; i <= p; ++i)
        m[divs[i]] = i;
    for (int i = 1; i <= p; ++i){
        pd[i][i] = 1;
        for (int j = i-1; j >= 1; --j){
            pd[i][j] = pd[i][j+1];
            if(divs[i]%divs[j] == 0)
                pd[i][j] += pd[m[divs[i]/divs[j]]][j];
        }
    }
    fout << pd[p][1] << "\n";
    test = pd[p][1]-test+1;
    int lft = p;
    while(lft != 0){
        int nxt = lft;
        for (int i = lft; ; --i)
            if(pd[lft][i] >= test){
                test -= pd[lft][i+1];
                nxt = i;
                break;
            }
        fout << divs[nxt] << " ";
        lft = m[divs[lft]/divs[nxt]];
    }
    return 0;
}

