#include <bits/stdc++.h>

using namespace std;

struct thing{
    int i;
    vector<int> t;

    bool operator<(const thing &obj)const{
        return i < obj.i;
    }
};

vector<thing> sol[1005], res;
long long v[1005][2005], v2[1005][2005], test;
char s[20000];
bool ok[2005];

thing make_thing(int i, vector<int> &t)
{
    thing aux;
    aux.i = i;
    aux.t = t;
    return aux;
}

int main()
{
    ifstream fin ("permutare4.in");
    ofstream fout ("permutare4.out");
    for(int tt = 1; fin >> test; ++tt){
        thing t; t.i = tt;
        if(test == 1){
            int n, m;
            fin >> n >> m;
            t.t.push_back(m);
            sol[n].push_back(t);
        }else{
            int n;
            fin >> n;
            for (int i = 1; i <= n; ++i){
                int x;
                fin >> x;
                t.t.push_back(x);
            }
            int x;
            for (int i = 1; i <= n; ++i)
                fin >> x;
            sol[n].push_back(t);
        }
    }
    for (int t = 3; t <= 1000; ++t){
        for (int j = t*2-1; j >= t; --j)
            v[t][j] = v[t][j+1] + 1,
            v2[t][j] = 1;
        for (int i = t-1; i > 0; --i)
            for (int j = i*2-1; j >= i; --j){
                if(v[i+1][j+1] > -1 && v[i][j+1] > -1){
                    v[i][j] = v[i][j+1] + v[i+1][j+1];
                    if(v[i][j] > 10000000100000000)
                        v[i][j] = -1;
                }else v[i][j] = -1;
                if(v[i+1][j+1] == -1)
                    v2[i][j] = -1;
                else v2[i][j] = v[i+1][j+1];

                if(v[i][j] == -1){
                    v[i][i] = -1;
                    break;
                }
            }
        for (vector<thing>::iterator it1 = sol[t].begin(); it1 != sol[t].end(); ++it1){
            thing T = *it1;
            if(T.t.size() > 1){
                int sum = 1;
                thing aux; aux.i = T.i;
                for (int i = 2; i <= t; ++i)
                    sum += v[i][T.t[i-2]+1] - v[i][T.t[i-1]];
                aux.t.push_back(sum);
                res.push_back(aux);
            }else{
                thing aux; aux.i = T.i;
                aux.t.push_back(1);
                int rem = T.t[0]-1;
                memset(ok, 0, sizeof(ok));
                for (int i = 2; i <= t; ++i){
                    int I = aux.t.back()+1;
                    for (int j = aux.t.back()+1; j < 2*i; ++j)
                        if(rem >= v2[i][j] && v2[i][j] != -1){
                            ++I;
                            rem -= v2[i][j];
                        }else break;
                    ok[I] = 1;
                    aux.t.push_back(I);
                }
                int now = 2;
                for (int i = 1; i <= t; ++i){
                    here:
                    if(ok[now]){
                        ++now;
                        goto here;
                    }
                    aux.t.push_back(now);
                    ++now;
                }
                res.push_back(aux);
            }
        }
    }
    sort(res.begin(), res.end());
    for (vector<thing>::iterator it = res.begin(); it != res.end(); ++it){
        for (vector<int>::iterator it2 = it->t.begin(); it2 != it->t.end(); ++it2)
            fout << *it2 << " ";
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

