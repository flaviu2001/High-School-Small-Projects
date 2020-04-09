#include <bits/stdc++.h>

using namespace std;

int64_t n, k, v[100005], sumk, sumn, ans, med;
set<int64_t> s;

int main()
{
    ifstream fin ("pikachu.in");
    ofstream fout ("pikachu.out");
    fin >> n >> k;
    for (int64_t i = 1; i <= n; ++i)
        fin >> v[i];
    for (int64_t i = 1; i <= k; ++i){
        s.insert(v[i]);
        sumn += v[i];
    }
    int64_t pos = (k+1)/2, ii = 1;
    for (set<int64_t>::iterator it = s.begin(); it != s.end(); ++it, ++ii)
        if(ii <= pos){
            sumk += *it;
            med = *it;
        }else break;
    ans = (med*pos-sumk) + ((sumn-sumk)-med*(k-pos));
    for (int64_t t = k+1; t <= n-1; ++t){
        int64_t x = v[t];
        int64_t rem = v[t-k];
        if(rem == med){
            if(x > med){
                s.erase(s.find(rem));
                s.insert(x);
                int64_t newmed = *s.upper_bound(med);
                sumk += newmed;
                sumk -= rem;
                sumn -= rem;
                sumn += x;
                med = newmed;
            }else{
                s.erase(s.find(rem));
                s.insert(x);
                set<int64_t>::iterator nw = s.lower_bound(med);
                --nw;
                int64_t newmed = *nw;
                sumk -= med;
                sumk += x;
                sumn += x;
                sumn -= rem;
                med = newmed;
            }
        }
        else if(x > med && rem > med){
            sumn -= rem;
            sumn += x;
            s.erase(s.find(rem));
            s.insert(x);
        }else if (x < med && rem < med){
            sumn -= rem;
            sumn += x;
            sumk -= rem;
            sumk += x;
            s.erase(s.find(rem));
            s.insert(x);
        }else if ( x > med && rem < med){
            s.erase(s.find(rem));
            s.insert(x);
            int64_t newmed = *s.upper_bound(med);
            sumk += newmed;
            sumk -= rem;
            sumn -= rem;
            sumn += x;
            med = newmed;
        }else{ //if( x < med && rem > med)
            s.erase(s.find(rem));
            s.insert(x);
            set<int64_t>::iterator nw = s.lower_bound(med);
            --nw;
            int64_t newmed = *nw;
            sumk -= med;
            sumk += x;
            sumn += x;
            sumn -= rem;
            med = newmed;
        }
        ans = min(ans, (med*pos-sumk) + ((sumn-sumk)-med*(k-pos)));
    }
    fout << ans << "\n";
    return 0;
}

