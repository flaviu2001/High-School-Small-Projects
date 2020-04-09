#include <bits/stdc++.h>

using namespace std;

int x1, x2, x3, x4, x5, sol;
unordered_map<int, int> mp;

int main()
{
    ifstream fin ("eqs.in");
    ofstream fout ("eqs.out");
    fin >> x1 >> x2 >> x3 >> x4 >> x5;
    for (int i1 = -50; i1 <= 50; ++i1)
        for (int i2 = -50; i2 <= 50; ++i2){
            if(i1*i2 == 0)
                continue;
            int x = i1*i1*i1*x1+i2*i2*i2*x2;
            ++mp[x];
        }
    for (int i1 = -50; i1 <= 50; ++i1)
        for (int i2 = -50; i2 <= 50; ++i2)
            for (int i3 = -50; i3 <= 50; ++i3){
                int y = i1*i1*i1*x3+i2*i2*i2*x4+i3*i3*i3*x5;
                if(mp.find(-y) != mp.end() && i1*i2*i3 != 0)
                    sol += mp[-y];
            }
    fout << sol << "\n";
    return 0;
}

