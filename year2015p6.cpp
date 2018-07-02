#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000007

ll modinv(ll a) {
	ll m = MOD - 2, res = 1;
	while(m) {
		if(m & 1)
			res *= a, res %= MOD;
		a *= a, a %= MOD;
		m >>= 1;
	}
	return res;
}

#define MAXM 51

ll bc(ll n, ll k) {
	ll num = 1, den = 1;
	for(ll i = 1; i <= k; i++)
		num *= n + 1 - i, den *= i, num %= MOD, den %= MOD;
	return num * modinv(den) % MOD;
}

int n, m;
ll dp[MAXM][32][MAXM][MAXM];
vector<pii> preproc;

ll f(int i, int j, int k, int l) {
	if(l > n || k > n)
		return 0;
	if(i < 0)
		return 0;
	if(k == n && i > 0)
		return 0;
	ll &res = dp[i][j][k][l];
	if(res != -1)
		return res;
	res = 0;
	if(i == 0)
	{
		ll bars = l, stars = n - l - k;
		res += bc(bars + stars, bars );
	}
	else
		for(pii v : preproc)
			res += f(i - v.second, v.first, k + ((j & v.first) ? 1 : 0), l + 1);

	res %= MOD;
	return res;
}

int popcnt(int i)
{
	int res = 0;
	bool lst = false;
	while(i) {
		if(i & 1) {
			if(lst)
				return -1;
			else
				res++;
		}
		lst = i & 1;
		i >>= 1;
	}
	return res;
}

int main() {
	for(int nxt = 0; nxt < 32; nxt++) {
		int alt = popcnt(nxt);
		if(alt == -1)
			continue;
		preproc.push_back({nxt, alt});
	}
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	printf("%lld\n", f(m, 0, 0, 0));
}
