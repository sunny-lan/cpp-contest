#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
#define MAXN 1000001
int n;
int l[MAXN], r[MAXN];
int lm, rm ;
int dp[MAXN];
int c[MAXN], nxt[MAXN];
int f(int x, int dj[]) {
	if(dj[x] == x)
		return x;
	return dj[x] = f(dj[x], dj);
}
void mrg(int x, int y) {
	int px = f(x, c), py = f(y, c);
	if(px == py)
		return;
	l[py] = min(l[py], l[px]);
	r[py] = max(r[py], r[px]);
	c[px] = py;
}
int dfs(int i) {
	if(i < 0 || i >= n)
		return 1 << 30;
	if(l[f(i, c)] == lm && r[f(i, c)] == rm)
		return 0;
	if(dp[l[f(i, c)]] != -1)
		return dp[l[f(i, c)]];
	dp[i] = 1 << 30;
	return dp[l[f(i, c)]] = min(dfs(l[f(i, c)] - 1), dfs(r[f(i, c)] + 1)) + 2;
}
ll minimum_walk(vector<int> p, int s) {
	memset(dp, -1, sizeof dp);
	lm = -1, rm = -2;
	n = p.size();
	ll tot = 0;
	for(int i = 0; i <= n; i++)
		l[i] = r[i] = c[i] = nxt[i] = i;
	set<pii> q;
	for(int i = 0; i < n; i++) {
		tot += abs(i - p[i]);
		if(c[i] != i)
			continue;
		int tmp = i;
		do {
			tmp = p[tmp];
			mrg(tmp, i);
		} while(tmp != i);
		q.insert({r[i] - l[i], i});
	}
	while(!q.empty()) {
		auto ksut = q.begin();
		int cur = ksut->s, cloc=f(l[cur], nxt);
		q.erase(ksut);
		int j = cloc + 1;
		if(j<n && j < r[cur]) {
			nxt[cloc] = j;
			int mi = f(j, c);
			q.erase({r[mi] - l[mi], mi});
			if(r[mi] > r[cur] || l[mi]<l[cur])
				mrg(mi, cur);
			q.insert({r[cur] - l[cur], cur});
		}
	}
	for(int i = 0; i < n; i = r[f(i, c)] + 1) {
		if(s >= l[f(i, c)] && s <= r[f(i, c)])
			if(r[f(i, c)] - l[f(i, c)] > rm - lm)
				lm = l[f(i, c)], rm = r[f(i, c)];
	}
	bool flg = false;
	for(int i = 0; i < lm; i = r[f(i, c)] + 1) {
		if(l[f(i, c)] != r[f(i, c)])
			flg = true;
		if(flg)
			tot += 2;
	}
	flg = false;
	for(int i = n - 1; i > rm; i = l[f(i, c)] - 1) {
		if(l[f(i, c)] != r[f(i, c)])
			flg = true;
		if(flg)
			tot += 2;
	}
	tot += dfs(s);
	return tot;
}
