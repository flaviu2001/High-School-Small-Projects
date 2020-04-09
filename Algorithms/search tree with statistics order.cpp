//http://codeforces.com/blog/entry/11080

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree< pair<int, string>, null_type, less< pair<int, string> >, rb_tree_tag, tree_order_statistics_node_update> Set;
 
int test;
Set s;
 
int main()
{
    ifstream fin ("nums.in");
    ofstream fout ("nums.out");
    fin >> test;
    while(test--){
        int t;
        fin >> t;
        if(t == 1){
            string ss;
            fin >> ss;
            s.insert({ss.length(), ss});
        }else{
            int x;
            fin >> x;
            fout << (*s.find_by_order(x-1)).second << "\n";
        }
    }
    return 0;
}
