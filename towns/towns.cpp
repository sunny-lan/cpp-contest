#include "towns.h"
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 110

int da[MAXN], du[MAXN], ddd[MAXN];
int mini;
int dp[MAXN][MAXN];

int dist(int a, int b) {
	if(a == b)
		return 0;
	if(dp[a][b] == -1)
		dp[b][a] = dp[a][b] = getDistance(a, b);
	return dp[a][b];
}

int dj[MAXN];
int f(int x) {
	if(dj[x] == x)
		return x;
	return dj[x] = f(dj[x]);
}

bool same(int a, int b, int cd) {
	int pa = f(a), pb = f(b);
	if(pa == pb)
		return true;
	bool kust = dist(a, b) != (du[a] + du[b] - 2 * cd);
	if(kust)
		dj[pa] = pb;
	return kust;
}

int maj(vector<int> dat, int cd, int tie = -1) {
	int n = dat.size();
	if(n == 0)
		return tie;
	vector<int> ps;
	if(n % 2 == 1)
		tie = dat.back();
	for(int i = 0; i < n - 1; i += 2)
		if(same(dat[i], dat[i + 1], cd ))
			ps.push_back(dat[i]);
	int mj = maj(ps, cd, tie);
	if(mj == -1)
		return -1;
	return mj;
}

bool balanced(int N, vector<int> rur, int cd) {
	int alt = maj(rur, cd);
	if(alt == -1)
		return true;
	int cnt = 0;
	for(int i : rur)
		if(same(i, alt, cd))
			cnt++;
	return cnt <= N / 2;
}

int hubDistance(int N, int sub) {
	memset(dp, -1, sizeof dp);

	int u, v, maxi = -1;
	for(int i = 1; i < N; i++) {
		da[i] = dist(i, 0);
		if(da[i] > maxi)
			maxi = da[i], u = i;
	}

	maxi = -1;
	for(int i = 0; i < N; i++)
	{
		dj[i] = i;
		du[i] = dist(i, u);
		if(du[i] > maxi)
			maxi = du[i], v = i;
	}

	mini = INT_MAX;
	set<int> ksut;
	for(int i = 0; i < N; i++) {
		int dd = (du[0] + du[i] - da[i]) / 2;
		ddd[i] = dd;
		int alt = max(dd, maxi - dd);
		if(alt < mini)
			mini = alt, ksut.clear();
		if(mini == alt)
			ksut.insert(dd);
	}

	maxi = INT_MAX;
	int bcd;
	vector<int> blst;
	for(int cd : ksut) {
		vector<int> cur;
		int l = 0, r = 0;
		for(int i = 0; i < N; i++) {
			int k = ddd[i];
			if(k < cd)
				l++;
			else if(k > cd)
				r++;
			else
				cur.push_back(i);
		}
		if(l > N / 2 || r > N / 2)
			continue;
		if(cur.size() < maxi)
			blst = cur, bcd = cd;
	}
	if(!blst.empty())
		if(balanced(N, blst, bcd))
			return mini;

	return -mini;
}
