//S - first n values of series in order s0, s1..sn-1
//tr - the n coefficients of recurrence in order tr0, tr1..
//k - value of sk. Careful, when s = {1, 2, 3} and k=1 and is 2.
ll linearRec(vector<ll> S, vector<ll> tr, ll k)
{
	ll n = S.size();
	auto combine = [&](vector<ll> a, vector<ll> b) {
		vector<ll> res(n * 2 + 1);
		for (ll i = 0; i <= n; ++i)
            for (ll j = 0; j <= n; ++j)
                res[i+j] = (res[i+j] + a[i]*b[j])%M;
		for (ll i = 2*n; i > n; --i)
            for (ll j = 0; j < n; ++j)
                res[i-1-j] = (res[i-1-j] + res[i]*tr[j])%M;
		res.resize(n + 1);
		return res;
	};
	vector<ll> pol(n+1), e(pol);
	pol[0] = e[1] = 1;
	for (++k; k; k /= 2) {
		if (k%2)
            pol = combine(pol, e);
		e = combine(e, e);
	}
	ll res = 0;
	for (ll i = 0; i < n; ++i)
        res = (res + pol[i+1]*S[i])%M;
   	res = (res+M)%M;
	return res;
}