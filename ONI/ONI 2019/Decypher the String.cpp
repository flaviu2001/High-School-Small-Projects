#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

char ans[100005];
string s, q1, a1, q2, a2, q3, a3;

int main()
{
    //ifstream cin ("data.in");
    cin >> s;
    int p = 0;
    bool ok = 1;
    for (int k = 1; k <= 676 && ok; ++k)
        for (char i = 'a'; i <= 'z' && ok; ++i){
            for (int j = 1; j <= 26; ++j){
                q1 += i;
                ++p;
                if(p == s.length()){
                    ok = 0;
                    break;
                }
            }
        }
    cout << "? " << q1 << endl;
    cin >> a1;
    ok = 1;
    p = 0;
    for (int k = 1; k <= 676 && ok; ++k)
        for (int j = 1; j <= 26 && ok; ++j)
            for (char i = 'a'; i <= 'z'; ++i){
                q2 += i;
                ++p;
                if(p == s.length()){
                    ok = 0;
                    break;
                }
            }
    cout << "? " << q2 << endl;
    cin >> a2;
    ok = 1;
    p = 0;
    for (char i = 'a'; i <= 'z'; ++i)
        for (int j = 1; j <= 676 && ok; ++j){
            q3 += i;
            ++p;
            if(p == s.length()){
                ok = 0;
                break;
            }
        }
    cout << "? " << q3 << endl;
    cin >> a3;
    for (int i = 0; i < s.length(); ++i)
        ans[676*(a3[i]-'a')+26*(a1[i]-'a')+a2[i]-'a'] = s[i];
    cout << "! " << ans << endl;
    return 0;
}