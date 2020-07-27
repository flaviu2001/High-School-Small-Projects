#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define int ll

ifstream redirect;
const string file = "data";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647;

void prepare_IO()
{
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	#else
		redirect.open(file+".in");
		cin.rdbuf(redirect.rdbuf());
	#endif
}

void solve()
{

}

signed main()
{
	prepare_IO();
	int test = 1;
	cin >> test;
	for (int testcase = 1; testcase <= test; ++testcase)
		solve();
	return 0;
}

