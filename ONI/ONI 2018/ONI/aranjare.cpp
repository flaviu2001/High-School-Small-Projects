#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s0, s1, s2;
vector< pair<int, int> > sol;

int main()
{
    ifstream fin ("aranjare3.in");
    ofstream fout ("aranjare3.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        s0.push(x);
    }
    int pw = 1;
    while(pw <= n){
        for (int i = 1; i <= n; ++i){
            int x = s0.top();
            s0.pop();
            if(x&pw){
                s2.push(x);
                sol.push_back({0, 2});
            }else{
                s1.push(x);
                sol.push_back({0, 1});
            }
        }
        while(!s1.empty()){
            s0.push(s1.top());
            s1.pop();
            sol.push_back({1, 0});
        }
        while(!s2.empty()){
            s0.push(s2.top());
            s2.pop();
            sol.push_back({2, 0});
        }
        pw *= 2;
    }
    fout << "2 " << sol.size() << "\n";
    for (vector< pair<int, int> >::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    return 0;
}

