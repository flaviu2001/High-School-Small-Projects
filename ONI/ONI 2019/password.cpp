#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, a;
string s;

string rec(char st, char dr)
{
    if(st == dr){
        string qr;
        for (int i = 1; i <= n; ++i)
            qr = qr + st;
        cout << qr << endl;
        qr = "";
        int x;
        cin >> x;
        for (int i = 1; i <= x; ++i)
            qr = qr + st;
        return qr;
    }else{
        char m = st+(dr-st)/2;
        string l = rec(st, m);
        string r = rec(m+1, dr);
        int len = l.length(), p = 0;
        for (int i = 0; i <= len && p < r.length(); ++i){
            bool ok;
            do{
                ok = false;
                string now = l;
                now.insert(now.begin()+i+p, r[p]);
                int x;
                cout << now  << endl;
                cin >> x;
                if(x == now.length()){
                    ok = true;
                    l = now;
                    ++p;
                }
            }while(ok && p < r.length());
        }
        return l;
    }
}

int main()
{
    cin >> n >> a;
    rec('a', 'a'+a-1);
    return 0;
}
