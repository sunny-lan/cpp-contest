#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second

pll operator +(pll a, pll b) {
	return {a.f + b.f, a.s + b.s};
}

int n;
string a, b;
pll dp[16][11][16][2][2];

pll f(int dig = 0, int lst = 10, int consec = 0, int hi = 1, int lo = 1) {
	ll pls = consec * consec * lst;
	if(dig == n)
		return {1, pls};
	pll &res = dp[dig][lst][consec][hi][lo];
	if(res.f != -1)
		return res;
	res = {0, 0};
	int ad = a[dig] - '0',
		bd = b[dig] - '0',
		ed = hi ? bd : 9,
		st = lo ? ad : 0;
	for(int i = st; i <= ed; i++)
		if(i == lst)
			res = res + f(dig + 1, i, consec + 1, hi & (i == bd ? 1 : 0), lo & (i == ad ? 1 : 0));
		else {
			pll alt = f(dig + 1, i, 1, hi & (i == bd ? 1 : 0), lo & (i == ad ? 1 : 0) );
			alt = {alt.f, alt.s + alt.f * pls};
			res = res + alt;
		}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	n = max(a.length(), b.length());
	while(a.length() < n)
		a = "0"+a ;
	while(b.length() < n)
		b =  "0"+b ;
	printf("%lld", f().s);
}
