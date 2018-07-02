#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define MAXN 2005
typedef long long ll;
vector<int> adj[MAXN];
vector<ll> psa[MAXN];
int p[MAXN];ll cnt[MAXN][MAXN];
void init(int i = 0, int j = -1) {
	p[i] = j;
	for(int k : adj[i]) {
		if(k != j) {
			init(k, i);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}

	init();

	for(int i = 0; i < n; ++i) {
		for(int j = i, dst = 0; j != -1; j = p[j], ++dst)
			cnt[j][dst]++;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 1; j < n; ++j)
			cnt[i][j] += cnt[i][j - 1];
	}

	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		ll sm = 0, ans = 0;
		for(int j = 0; j < adj[a].size(); ++j) {
			int k = adj[a][j];
			ans += sm * cnt[k][b - 1];
			sm += cnt[k][b - 1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
