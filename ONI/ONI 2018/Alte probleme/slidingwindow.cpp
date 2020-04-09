#include <bits/stdc++.h>

using namespace std;

int n, d, v[1000005], l, sol = 1<<30;
multiset<int> s;

int main()
{
    ifstream fin ("slidingwindow.in");
    ofstream fout ("slidingwindow.out");
    fin >> n >> d;
    ++d;
    fin >> v[1] >> v[2];
    sol = abs(v[2]-v[1]);
    s.insert(v[1]);
    s.insert(v[2]);
    for (int i = 3; i <= n; ++i){
        fin >> v[i];
        if(i-d > 0)
            s.erase(s.find(v[i-d]));
        multiset<int>::iterator i1 = s.lower_bound(v[i]), i2 = s.lower_bound(v[i]), ed = s.end();
        --ed;
        --i2;
        if(*i1 == v[i])
            sol = 0;
        else if(v[i] < *(s.begin()))
            sol = min(sol, *(s.begin())-v[i]);
        else if(v[i] > *(ed))
            sol = min(sol, v[i]-*(ed));
        else sol = min(sol, min((*i1)-v[i], v[i]-(*i2)));
        s.insert(v[i]);
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

