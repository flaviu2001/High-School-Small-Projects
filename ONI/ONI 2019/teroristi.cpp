#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<char, char> pc;

const string file = "teroristi";
const ll INF = 9223372036854775807ll;
const int inf = 1000000000;

int n, m, c[3005][3005], f[3005][3005], where[10005], p[3005], ans[1000006], italfa[30], itprs[1005];
vector<int> alfa[30], prs[1005], v[10005];
pc dil[1000006];
bool ok[3005];
string s;

bool bfs()
{
    queue<int> q;
    memset(ok, 0, sizeof(ok));
    q.push(1);
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(!ok[*it] && c[k][*it] > f[k][*it]){
                ok[*it] = 1;
                p[*it] = k;
                q.push(*it);
                if(*it == 3000)
                    return 1;
            }
    }
    return 0;
}


int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
        alfa[s[i]-'a'].push_back(i);
    for (int i = 1; i <= m; ++i){
        fin >> dil[i].ff >> dil[i].ss;
        if(dil[i].ff > dil[i].ss)
            swap(dil[i].ff, dil[i].ss);
        prs[(dil[i].ff-'a')*30+dil[i].ss-'a'].push_back(i);
    }
    int st = 2;
    for (int i = 0; i < 26; ++i){
        v[1].push_back(st);
        v[st].push_back(1);
        c[1][st] = inf;
        v[st].push_back(st+1);
        v[st+1].push_back(st);
        v[st+1].push_back(st+2);
        v[st+2].push_back(st+1);
        c[st][st+1] = alfa[i].size();
        c[st+1][st+2] = alfa[i].size();
        st += 3;
    }
    for (int i = 0; i < 3005; ++i)
        where[i] = -1;
    for (int i = 0; i < 1005; ++i)
        if(prs[i].size() != 0){
            v[st].push_back(st+1);
            v[st+1].push_back(st);
            v[st+1].push_back(st+2);
            v[st+2].push_back(st+1);
            c[st][st+1] = prs[i].size();
            c[st+1][st+2] = prs[i].size();
            v[st+2].push_back(3000);
            v[3000].push_back(st+2);
            c[st+2][3000] = inf;
            where[st] = where[st+1] = where[st+2] = i;
            char a = dil[prs[i][0]].ff, b = dil[prs[i][0]].ss;
            v[(a-'a'+1)*3].push_back(st);
            v[st].push_back((a-'a'+1)*3);
            c[(a-'a'+1)*3][st] = inf;
            v[(b-'a'+1)*3].push_back(st);
            v[st].push_back((b-'a'+1)*3);
            c[(b-'a'+1)*3][st] = inf;
            st += 3;
        }
    int flow = 0;
    while(bfs())
        for (vector<int>::iterator it = v[3000].begin(); it != v[3000].end(); ++it)
            if(ok[*it] && f[*it][3000] < c[*it][3000]){
                p[3000] = *it;
                int nod = 3000, mn = inf;
                while(nod != 1){
                    mn = min(mn, c[p[nod]][nod]-f[p[nod]][nod]);
                    nod = p[nod];
                }
                if(mn == 0)
                    continue;
                nod = 3000;
                while(nod != 1){
                    f[p[nod]][nod] += mn;
                    f[nod][p[nod]] -= mn;
                    nod = p[nod];
                }
                flow += mn;
            }
    for (int i = 0; i < 26; ++i){
        memset(ok, 0, sizeof(ok));
        for (int j = 0; j < 3005; ++j)
            if(where[j] != -1 && !ok[where[j]] && f[(i+1)*3][j]){
                ok[where[j]] = 1;
                for (int k = 0; k < f[(i+1)*3][j]; ++k)
                    ans[alfa[i][italfa[i]++]] = prs[where[j]][itprs[where[j]]++];
            }
    }
    for (int i = 0; i < n; ++i)
        fout << ans[i] << " ";
    return 0;
}
