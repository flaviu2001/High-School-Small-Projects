#include <bits/stdc++.h>

using namespace std;

struct frunza{
    int nod, cost;

    bool operator<(const frunza &obj)const{
        return cost < obj.cost;
    }
};

vector<int> v[10005];
multiset<frunza> s;
int n, k, cost[10005], cost2[10005];
bool ok[10005];

frunza make_frunza(int nod, int cost)
{
    frunza aux;
    aux.nod = nod;
    aux.cost = cost;
    return aux;
}

int main()
{
    ifstream fin ("cezar1.in");
    ofstream fout ("cezar1.out");
    fin >> n >> k;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        cost[i] = 1;
        if(v[i].size() == 1)
            s.insert(make_frunza(i, 1));
    }
    int sol = 0;
    for (int i = 1; i < n-k; ++i){
        frunza u = *(s.begin());
        s.erase(s.begin());
        ok[u.nod] = 1;
        sol += cost[u.nod];
        for (vector<int>::iterator it = v[u.nod].begin(); it != v[u.nod].end(); ++it){
            cost[*it] += cost[u.nod];
            ++cost2[*it];
            if(cost2[*it]+1 == v[*it].size()){
                s.insert(make_frunza(*it, cost[*it]));
            }
        }
    }
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}

