#include <bits/stdc++.h>

using namespace std;

struct thing{
    long long son, val;
    bool operator<(const thing &obj)const{
        return val < obj.val;
    }
};

long long n, d[100005];
multiset<thing> v[100005];
bool ok[100005];

thing make_thing(long long son, long long val)
{
    thing aux;
    aux.son = son;
    aux.val = val;
    return aux;
}

void depth_df(long long x)
{
    ok[x] = 1;
    bool yea = 0;
    multiset<thing>::iterator the_one;
    for (multiset<thing>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if(!ok[it->son]){
            depth_df(it->son);
            d[x] += d[it->son]+it->val;
        }else{
            the_one = it;
            yea = 1;
        }
    if(yea)
        v[x].erase(the_one);
}

void main_df(long long x, long long h)
{
    ok[x] = 1;
    if(v[x].size() == 0 || h < v[x].begin()->val)
        return;
    for (multiset<thing>::iterator it = v[x].begin(); it != v[x].end(); ++it){
        long long experiment = h;
        for (multiset<thing>::iterator it2 = v[x].begin(); it2 != v[x].end(); ++it2)
            if(it2 != it && experiment >= it2->val)
                experiment += it2->val+d[it2->son];
            else if (experiment < it2->val)
                break;
        if(experiment < it->val)
            return;
        main_df(it->son, experiment-it->val);
    }
}

int main()
{
    ifstream fin ("invtree.in");
    ofstream fout ("invtree.out");
    long long h;
    fin >> n >> h;
    for (long long i = 1; i < n; ++i){
        long long x, y, z;
        fin >> x >> y >> z;
        v[x].insert(make_thing(y, z));
        v[y].insert(make_thing(x, z));
    }
    depth_df(1);
    memset(ok, 0, sizeof(ok));
    main_df(1, h);
    for (long long i = 1; i <= n; ++i)
        fout << ok[i];
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

