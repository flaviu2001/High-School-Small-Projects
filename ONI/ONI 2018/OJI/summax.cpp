#include <bits/stdc++.h>
#define LL (long long)

using namespace std;

const int f = 2000*2001/2;

ifstream fin ("summax.in");
ofstream fout ("summax.out");
int test, n, st, dr, mx;
vector<int> t;
int v[4002001];

int mat(int i1, int j1)
{
    int ans = i1*(i1-1)/2;
    ans += j1;
    return ans;;
}

void rec(int lo, int hi, int i1, int j1)
{
    t.push_back(j1);
    if(i1 == n){
        for (vector<int>::iterator it = t.begin(); it != t.end(); ++it)
            fout << *it << " ";
        fout << "\n";
    }else{
        if(v[mat(i1+1, j1)] > v[mat(i1+1, j1+1)])
            rec(lo, hi, i1+1, j1);
        else if (v[mat(i1+1, j1)] < v[mat(i1+1, j1+1)])
            rec(lo, hi, i1+1, j1+1);
        else{
            int lo1 = lo, hi1, lo2, hi2 = hi;
            hi1 = lo1-1 + v[mat(i1+1, j1)+f];
            lo2 = hi1+1;
            if(!(hi1 < st || dr < lo1))
                rec(lo1, hi1, i1+1, j1);
            if(!(hi2 < st || dr < lo2))
                rec(lo2, hi2, i1+1, j1+1);
        }
    }
    t.pop_back();
}

int main()
{
    fin >> test >> n >> st >> dr;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j)
            fin >> v[mat(i, j)];
    }
    for (int i = 1; i <= n; ++i)
        v[mat(n, i)+f] = 1;
    for (int i = n-1; i > 0; --i)
        for (int j = 1; j <= i; ++j)
            v[mat(i, j)] += max(v[mat(i+1, j)], v[mat(i+1, j+1)]);
    for (int i = n-1; i > 0; --i)
        for (int j = 1; j <= i; ++j){
            if(v[mat(i+1, j)] == v[mat(i+1, j+1)]){
                if(LL v[mat(i+1, j)+f] + LL v[mat(i+1, j+1)+f] > 2000000000)
                    v[mat(i, j)+f] = 2000000001;
                else
                    v[mat(i, j)+f] = v[mat(i+1, j)+f] + v[mat(i+1, j+1)+f];
            }
            else if (v[mat(i+1, j)] > v[mat(i+1, j+1)])
                v[mat(i, j)+f] = v[mat(i+1, j)+f];
            else
                v[mat(i, j)+f] = v[mat(i+1, j+1)+f];
        }
    if(test == 1)
        fout << v[mat(1, 1)+f] << "\n";
    else
        rec(1, v[mat(1, 1)+f], 1, 1);
    fin.close();
    fout.close();
    return 0;
}

