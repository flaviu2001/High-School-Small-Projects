#include <bits/stdc++.h>

using namespace std;

vector<int> v[100005];
queue< pair<int, int> > q;
int n, t, d1[100005], d2[100005], prd[100005];
bool ok[100005], node2[100005]; //node2 is an awful name. it just represents whether the bf found a second leaf for node i

void bf() //in this particular source code i find more convenient to write the bf outside of main. Deal with it
{
    while(!q.empty()){
        int k = q.front().first;
        int pred = q.front().second;
        q.pop();
        for (vector<int>::iterator it = v[k].begin(); it != v[k].end(); ++it)
            if(*it != pred){
                if(!ok[*it]){
                    ok[*it] = 1;
                    prd[*it] = prd[k];
                    d1[*it] = d1[k] + 1;
                    q.push(make_pair(*it, k));
                }else if(!node2[*it]){
                    node2[*it] = 1;
                    if(prd[*it] != prd[k])
                        d2[*it] = d1[k]+1;
                    else
                        d2[*it] = d2[k]+1;
                    q.push(make_pair(*it, k));
                }
            }
    }
}

int main()
{
    ifstream fin ("statiuni.in");
    ofstream fout ("statiuni.out");
    fin >> n >> t;
    for (int i = 1; i < n; ++i){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].size() == 1){
            q.push(make_pair(i, 0));
            ok[i] = 1;
            prd[i] = i;
        }
    bf();
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if(node2[i] && d2[i] <= t)
            ++k;
    fout << k << "\n";
    return 0;
}

