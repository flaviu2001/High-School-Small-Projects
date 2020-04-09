#include <bits/stdc++.h>
 
using namespace std;
 
int n;
string s1, s2, s3;
char sol[1000006];
vector<int> n1, n2, n3, n0;
 
int main()
{
    ifstream fin ("cstring.in");
    ofstream fout ("cstring.out");
    fin >> n >> s1 >> s2 >> s3;
    for (int i = 0; i < n; ++i)
        if(s1[i] == s2[i] && s2[i] == s3[i])
            sol[i] = s1[i];
        else if (s1[i] != s2[i] && s2[i] != s3[i] && s1[i] != s3[i])
            n0.push_back(i);
        else if (s2[i] == s3[i])
            n1.push_back(i);
        else if (s1[i] == s3[i])
            n2.push_back(i);
        else n3.push_back(i);
    while(n0.size() > 0 && n1.size()+n2.size()+n3.size() > 0){
        int sz = max(max(n1.size(), n2.size()), n3.size()), a0 = n0.back();
        n0.pop_back();
        if(n1.size() == sz){
            int a1 = n1.back();
            n1.pop_back();
            sol[a1] = s2[a1];
            sol[a0] = s1[a0];
        }else if (n2.size() == sz){
            int a1 = n2.back();
            n2.pop_back();
            sol[a1] = s1[a1];
            sol[a0] = s2[a0];
        }else{
            int a1 = n3.back();
            n3.pop_back();
            sol[a1] = s1[a1];
            sol[a0] = s3[a0];
        }
    }
    if(n0.size() > 0){
        for (int i = 0; i < n0.size(); ++i)
            switch(i%3){
                case 0:{
                    sol[n0[i]] = s1[n0[i]];
                    break;
                }
                case 1:{
                    sol[n0[i]] = s2[n0[i]];
                    break;
                }
                case 2:{
                    sol[n0[i]] = s3[n0[i]];
                    break;
                }
            }
    }else if (n1.size()+n2.size()+n3.size() > 0){
        int sz = max(max(n1.size(), n2.size()), n3.size());
        if(n1.size() == sz){
            for (auto x : n2)
                sol[x] = s1[x];
            for (auto x : n3)
                sol[x] = s1[x];
            int p = 0;
            while(p < max(n2.size(), n3.size())){
                sol[n1[p]] = s2[n1[p]];
                ++p;
            }
            int yes = 1;
            while(p < n1.size()){
                /*if(p < 0 || p >= n1.size() || n1[p] >= s1.length() || n1[p] >= s2.length()){
                    cout << n1[p] << " " << s1.length() << " " << s2.length();
                    return 0;
                }*/
                if(yes)
                    sol[n1[p]] = s1[n1[p]];
                else sol[n1[p]] = s2[n1[p]];
                yes = 1 - yes;
                ++p;
            }
        }else if (n2.size() == sz){
            for (auto x : n1)
                sol[x] = s2[x];
            for (auto x : n3)
                sol[x] = s2[x];
            int p = 0;
            while(p < max(n1.size(), n3.size())){
                sol[n2[p]] = s1[n2[p]];
                ++p;
            }
            int yes = 1;
            while(p < n2.size()){
                if(yes)
                    sol[n2[p]] = s2[n2[p]];
                else sol[n2[p]] = s1[n2[p]];
                yes = 1 - yes;
                ++p;
            }
        }else{
            for (auto x : n1)
                sol[x] = s3[x];
            for (auto x : n2)
                sol[x] = s3[x];
            int p = 0;
            while(p < max(n1.size(), n2.size())){
                sol[n3[p]] = s1[n3[p]];
                ++p;
            }
            int yes = 1;
            while(p < n3.size()){
                if(yes)
                    sol[n3[p]] = s3[n3[p]];
                else sol[n3[p]] = s1[n3[p]];
                yes = 1 - yes;
                ++p;
            }
        }
    }
    fout << sol << "\n";
    return 0;
}
