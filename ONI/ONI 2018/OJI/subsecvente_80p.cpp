#include <bits/stdc++.h>

using namespace std;

struct thing{
    long long sz, nr;

    bool operator<(const thing &obj)const{
        if(sz < obj.sz)
            return true;
        if(sz > obj.sz)
            return false;
        if(nr < obj.nr)
            return true;
        if(nr > obj.nr)
            return false;
        return false;
    }

    bool operator>(const thing &obj)const{
        if(sz < obj.sz)
            return false;
        if(sz > obj.sz)
            return true;
        if(nr < obj.nr)
            return false;
        if(nr > obj.nr)
            return true;
        return false;
    }

    bool operator==(const thing &obj)const{
        return sz == obj.sz && nr == obj.nr;
    }
};

int n;
vector<thing> r[5], c[4], v[5];
char q[50005];

thing make_thing(long long sz, long long nr)
{
    thing aux;
    aux.sz = sz;
    aux.nr = nr;
    return aux;
}

void mergevectors(vector<thing> a, vector<thing> b, vector<thing> &d)
{
    d.empty();
    int i1 = 0, i2 = 0;
    while(i1 < (int)a.size() && i2 < (int)b.size())
        if(a[i1]<b[i2]){
            d.push_back(a[i1]);
            ++i1;
        }else{
            d.push_back(b[i2]);
            ++i2;
        }
    while(i1 < (int)a.size()){
        d.push_back(a[i1]);
        ++i1;
    }
    while(i2 < (int)b.size()){
        d.push_back(b[i2]);
        ++i2;
    }
}

int main()
{
    ifstream fin ("subsecvente.in");
    ofstream fout ("subsecvente.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> q;
        int m = strlen(q);
        for (int i1 = 0; i1 < m; ++i1){
            long long nr = 0;
            for (int j1 = i1; j1 < m && j1-i1+1 <= 60; ++j1){
                nr = nr*2 + (q[j1] == 'a');
                v[i].push_back(make_thing(j1-i1+1, nr));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());
    for (int i = 1; i <= n; ++i){
        r[i].push_back(v[i][0]);
        for (unsigned j = 1; j < v[i].size(); ++j)
            if(!(v[i][j] == v[i][j-1]))
                r[i].push_back(v[i][j]);
    }
    mergevectors(r[1], r[2], c[1]);
    if(n > 2)
        mergevectors(c[1], r[3], c[2]);
    if(n > 3)
        mergevectors(c[2], r[4], c[3]);
    for (int i = c[n-1].size(); ; --i){
        int k = 1;
        for (int j = 1; j < n; ++j)
            if(c[n-1][i] == c[n-1][i-j])
                ++k;
        if(k == n){
            fout << c[n-1][i].sz << "\n";
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

