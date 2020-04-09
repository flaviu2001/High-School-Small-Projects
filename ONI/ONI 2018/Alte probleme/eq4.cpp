#include <bits/stdc++.h>

using namespace std;

int test, a, b, e, n, x, y, z, t, rem;
char c[100005];
vector<int> v;

int main()
{
    ifstream fin ("eq4.in");
    ofstream fout ("eq4.out");
    fin >> test;fin.get();
    fin.getline(c, 100005);
    fin >> a >> b >> e;
    n = strlen(c);
    int sign, curr;
    for (int tt = 0; tt < n; ++tt){
        char q = c[tt];
        if(q == '+' || q == '-'){
            sign = (q == '+' ? 1 : -1);
            curr = 0;
        }else if(q >= '0' && q <= '9'){
            curr = curr*10+(q-'0');
            if(tt == n-1 || (c[tt+1] == '+' || c[tt+1] == '-'))
                rem += curr*sign;
        }else{
            if(c[tt-1] == '+' || c[tt-1] == '-')
                curr = 1;
            switch(q){
                case 'x':
                    x += curr*sign;
                    break;
                case 'y':
                    y += curr*sign;
                    break;
                case 'z':
                    z += curr*sign;
                    break;
                case 't':
                    t += curr*sign;
                    break;
            }
        }
    }
    if(test == 1){
        fout << x+y+z+t+rem << "\n";
    }else{
        e -= rem;
        for (int i = a; i <= b; ++i)
            for (int j = a; j <= b; ++j)
                v.push_back(x*i+y*j);
        sort(v.begin(), v.end());
        int sol = 0;
        for (int i = a; i <= b; ++i)
            for (int j = a; j <= b; ++j){
                int p1 = t*i+z*j;
                int lf = e-p1;
                int st = 0, dr = v.size()-1, m, ans1 = -1, ans2 = -1;
                for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                    if(v[m] < lf)
                        st = m+1;
                    else{
                        if(v[m] == lf)
                            ans1 = m;
                        dr = m-1;
                    }
                st = 0, dr = v.size()-1;
                for (m = (st+dr)/2; st <= dr; m = (st+dr)/2)
                    if(v[m] > lf)
                        dr = m-1;
                    else{
                        if(v[m] == lf)
                            ans2 = m;
                        st = m+1;
                    }
                if(ans1 != -1)
                    sol += ans2-ans1+1;
            }
        fout << sol << "\n";
    }
    return 0;
}

