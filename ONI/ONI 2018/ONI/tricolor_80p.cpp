#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nmax = 5005;
int n, test, g[nmax], white[nmax];
vector<int> v[nmax];
vector< pair<int, int> > blacks[nmax]; //pairs, waiting
bool ok[nmax];

int main()
{
    ifstream fin ("tricolor.in");
    ofstream fout ("tricolor.out");
    fin >> test;
    while(test--){
        fin >> n;
        memset(ok, 0, sizeof(ok));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; ++i){
            v[i].clear();
            blacks[i].clear();
        }
        for (int i = 1; i < n; ++i){
            int x, y;
            fin >> x >> y;
            ++g[x];
            ++g[y];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i){
            if(g[i] == 1)
                q.push(i);
            white[i] = 0;
            blacks[i].push_back({0, 0});
        }
        int sol = 0;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(ok[k])
                continue;
            ok[k] = 1;
            for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
                if(!ok[*it]){
                    int tt = *it;
                    //CASE :: WHITE
                        int toadd = 0;
                        //SUBCASE :: WHITE
                        toadd = white[k]+1;
                        //SUBCASE :: BLACK
                        for (vector< pair<int, int> >::iterator it = blacks[k].begin(); it != blacks[k].end(); ++it)
                            toadd = max(toadd, it->first+it->second);
                    white[tt] += toadd;
                    //CASE :: BLACK
                        //SUBCASE :: WHITE
                        vector< pair<int, int> >newblack;
                        unordered_set<ll> s;
                        unordered_map<int, int> mp, mp2;
                        for (vector< pair<int, int> >::iterator it = blacks[tt].begin(); it != blacks[tt].end(); ++it){
                            pair<int, int> toadd = {it->first+white[k]+it->second, it->second+1};
                            ll cod = 1ll*toadd.first*1000000000+toadd.second;
                            if(s.find(cod) == s.end()){
                                if(mp.find(toadd.first) != mp.end() && mp[toadd.first] >= toadd.second)
                                    continue;
                                if(mp2.find(toadd.second) != mp2.end() && mp2[toadd.second] >= toadd.first)
                                    continue;
                                mp[toadd.first] = toadd.second;
                                mp2[toadd.second] = toadd.first;
                                s.insert(cod);
                                newblack.push_back(toadd);
                            }
                        }
                        //SUBCASE :: BLACK
                            for (vector< pair<int, int> >::iterator it = blacks[k].begin(); it != blacks[k].end(); ++it)
                                for (vector< pair<int, int> >::iterator it2 = blacks[tt].begin(); it2 != blacks[tt].end(); ++it2){
                                    pair<int, int> toadd = {it->first+it2->first+it->second*it2->second, it->second+it2->second};
                                    ll cod = 1ll*toadd.first*1000000000+toadd.second;
                                    if(s.find(cod) == s.end()){
                                        if(mp.find(toadd.first) != mp.end() && mp[toadd.first] >= toadd.second)
                                            continue;
                                        if(mp2.find(toadd.second) != mp2.end() && mp2[toadd.second] >= toadd.first)
                                            continue;
                                        mp[toadd.first] = toadd.second;
                                        mp2[toadd.second] = toadd.first;
                                        s.insert(cod);
                                        newblack.push_back(toadd);
                                    }
                                }
                    //blacks[tt].clear();
                    blacks[tt] = newblack;
                    --g[tt];
                    sol = max(sol, white[tt]);
                    for (vector< pair<int, int> >::iterator it = blacks[tt].begin(); it != blacks[tt].end(); ++it)
                        sol = max(sol, it->first);
                    if(g[tt] == 1)
                        q.push(tt);
                }
        }
        fout << sol << "\n";
    }
    return 0;
}

