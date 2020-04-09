#include <bits/stdc++.h>
 
using namespace std;
 
struct thing{
    int x, y;
 
    bool operator<(const thing &obj)const{
        return x >= obj.x;
    }
};
 
struct que{
    int x;
    thing a;
};
 
vector<int> r;
vector<que> q1, q2;
int n, test, vmax, v[4005];
thing p[8005], local_best[8005];
 
thing make_thing(int x, int y)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    return aux;
}
 
que make_que(thing a, int x){
    que aux;
    aux.a = a;
    aux.x = x;
    return aux;
}
 
thing max(thing a, thing b)
{
    if(a.y-a.x < b.y-b.x)
        return a;
    return b;
}
 
int main()
{
    ifstream fin ("euro3.in");
    ofstream fout ("euro3.out");
    fin >> test;
    while(test--){
        fin >> n >> vmax;
        for (int i = 1; i <= n; ++i){
            fin >> v[i];
        }
        sort(v+1, v+n+1);
        r.clear();
        for (int i = 1; i <= vmax; ++i){
            p[i] = make_thing(-1, -1);
            local_best[i] = make_thing(-1, -1);
        }
        for (int i = 1; i <= n; ++i){
            q1.clear();
            q2.clear();
            int x = v[i];
            int nd = (int)r.size();
            if(p[x].x == -1)
                r.push_back(x);
            for (int j = 0; j < nd; ++j)
                if(r[j] + x <= vmax){
                    thing th = make_thing(p[r[j]].x, x);
                    if(th < p[r[j]+x] || p[r[j]+x].x==-1){
                        if(p[r[j]+x].x==-1)
                            r.push_back(r[j]+x);
                        q1.push_back(make_que(th, r[j]+x));
                    }
                    if(local_best[r[j]+x].x == -1)
                        q2.push_back(make_que(th, r[j]+x));
                    else if(local_best[r[j]+x].y-local_best[r[j]+x].x > th.y-th.x)
                        q2.push_back(make_que(th, r[j]+x));
                }
            p[x] = make_thing(x, x);
            local_best[x] = make_thing(x, x);
            for (vector<que>::iterator it = q1.begin(); it != q1.end(); ++it)
                p[it->x] = it->a;
            for (vector<que>::iterator it = q2.begin(); it != q2.end(); ++it)
                local_best[it->x] = it->a;
        }
        for (int i = 1; i <= vmax; ++i)
            if(local_best[i].x!=-1)
                fout << local_best[i].y-local_best[i].x << " ";
            else fout << "-1 ";
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
