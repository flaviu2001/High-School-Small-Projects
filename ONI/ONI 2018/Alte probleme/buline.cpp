#include <bits/stdc++.h>

using namespace std;

int nr[200005], sp[400005], sum, n, mx, l, r;
vector<int> v;
deque<int> d;

int suma(int lo, int hi)
{
    if(lo == 0)
        return sp[hi];
    return sp[hi] - sp[lo-1];
}

int main()
{
    ifstream fin ("buline.in");
    ofstream fout ("buline.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x, sign;
        fin >> x >> sign;
        if(sign == 0)
            x = -x;
        nr[i] = x;
        sum += x;
        sp[i-1] = sum;
        v.push_back(x);
    }
    for (int i = 1; i < n; ++i){
        v.push_back(nr[i]);
        sum += v.back();
        sp[n+i-1] = sum;
    }
    mx = nr[1];
    l = 1;
    r = 1;
    d.push_back(0);
    for (int i = 1; i < n+n-1; ++i){
        if(i-d.front() == n)
            d.pop_front();
        while(!d.empty() && suma(d.back(), i) <= v[i])
            d.pop_back();
        d.push_back(i);
        if(suma(d.front(), i) > mx){
            mx = suma(d.front(), i);
            l = d.front()+1;
            r = i-d.front()+1;
        }
    }
    fout << mx << " " << l << " " << r << "\n";
    fin.close();
    fout.close();
    return 0;
}

