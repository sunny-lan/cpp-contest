#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

#define MAXN 5001

vector<pil> adj[MAXN];

pli dp[MAXN][2]; //{mini, cnt}

pli dfs(int i, int sv, int j = -1, ll d = 0) {
	pli &res = dp[i][sv];
	if(res.first != -1)
		return res;

	res = {0, 0};
	ll maxi = -1;
	int ch = 0;
	bool kust = true;
	for(pil neigh : adj[i]) {
		int v = neigh.first;
		if(v == j)
			continue;
		kust = false;
		pli ap = dfs(v, 0, i, d + neigh.second),
			bp = dfs(v, 1, i, d + neigh.second);
		ll a = ap.first +  neigh.second * (ll)ap.second,
		   b = d + neigh.second + bp.first;
		if(a < b) {
			res.first += a, res.second += ap.second;
			if(sv) {
				ll alt = a - (bp.first + neigh.second);
				if(alt > maxi)
					maxi = alt;
				if(alt == maxi)
					ch = min(ch, bp.second);
			}
		}
		else {
			res.first += b;
			if(sv) {
				if(d >= maxi)
					maxi = d, ch = 0;
			}
		}
	}

	if(kust) {
		res = {0, 1};
	} else {
		if(maxi > 0)
			res.first -= maxi, res.second = ch;
		if(maxi == 0)
			res.second = min(res.second, ch);
	}

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		ll t;
		scanf("%d %d %lld", &u, &v, &t);
		u--, v--;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	printf("%lld", min(dfs(0, 0).first, dfs(0, 1).first));
}
