#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "multimi4";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, p;
vector<int> v[27];
char s[1005];

vector<int> intersect(vector<int> v1, vector<int> v2)
{
    vector<int> sol;
    int I1 = 0, I2 = 0;
    while(I1 < v1.size() && I2 < v2.size()){
        if(v1[I1] == v2[I2]){
            sol.push_back(v1[I1]);
            ++I1, ++I2;
        }else if(v1[I1] < v2[I2])
            ++I1;
        else ++I2;
    }
    return sol;
}

vector<int> join(vector<int> v1, vector<int> v2)
{
    vector<int> sol;
    int I1 = 0, I2 = 0;
    while(I1 < v1.size() && I2 < v2.size()){
        if(v1[I1] == v2[I2]){
            sol.push_back(v1[I1]);
            ++I1, ++I2;
        }else if(v1[I1] < v2[I2]){
            sol.push_back(v1[I1]);
            ++I1;
        }else{
            sol.push_back(v2[I2]);
            ++I2;
        }
    }
    while(I1 < v1.size()){
        if(sol.empty() || sol.back() < v1[I1])
            sol.push_back(v1[I1]);
        ++I1;
    }
    while(I2 < v2.size()){
        if(sol.empty() || sol.back() < v2[I2])
            sol.push_back(v2[I2]);
        ++I2;
    }
    return sol;
}

vector<int> evalJoin(), evalIntersect(), termen();

vector<int> evalJoin()
{
    vector<int> r = evalIntersect();
    while(s[p] == '+'){
        ++p;
        r = join(r, evalIntersect());
    }
    return r;
}

vector<int> evalIntersect()
{
    vector<int> r = termen();
    while(s[p] == '*'){
        ++p;
        r = intersect(r, termen());
    }
    return r;
}

vector<int> termen()
{
    vector<int> r;
    if(s[p] == '('){
        ++p;
        r = evalJoin();
        ++p;
    }else{
        r = v[s[p]-'A'];
        ++p;
    }
    return r;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        char q, q2;
        int first, last, skip;
        fin >> q;
        fin >> q2;
        fin >> first;
        fin >> q2;
        fin >> last;
        fin >> q2;
        fin >> skip;
        for(int i = first; i <= last; i += skip)
            v[q-'A'].push_back(i);
    }
    fin >> s;
    vector<int> sol = evalJoin();
    fout << sol.size() << "\n";
    for (auto x : sol)
        fout << x << " ";
    return 0;
};
