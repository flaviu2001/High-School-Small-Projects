#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> Set;
Set s;

ll test;

int main()
{
    ifstream fin ("pitricele.in");
    ofstream fout ("pitricele.out");
    fin >> test;
    ll last = 0, add = 0;
    for (ll tst = 1; tst <= test; ++tst){
        ll g, r, x;
        fin >> g >> r >> x;
        g ^= last;
        r ^= last;
        x ^= last;
        if(tst != 1)
            add += g;
        s.insert(r+add);
        last = *s.find_by_order(x-1)-add;
        fout << last << "\n";
    }
    return 0;
}

