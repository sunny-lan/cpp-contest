#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <functional>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 100000

int djm[MAXN];
int findm(int x) {
	if (djm[x] == x)return x;
	return djm[x] = findm(djm[x]);
}

int djn[MAXN];
int findn(int x) {
	if (djn[x] == x)return x;
	return djn[x] = findn(djn[x]);
}

int main() {
	vector<pair<ll, pair<bool, pii>>> edges;
	ll tot = 0;
	int n, m, p, q; scanf("%d %d %d %d", &n, &m, &p, &q);
	int dp = n, dc = m;
	for (int i = 0; i < n; i++)
		djn[i] = i;
	for (int i = 0; i < m; i++)
		djm[i] = i;
	for (int i = 0; i < p; i++) {
		int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
		a--, b--;
		edges.push_back({ c, {false, {a,b}} });
		tot += c*n;
	}
	for (int i = 0; i < q; i++) {
		int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
		a--, b--;
		edges.push_back({ c,{ true,{ a,b } } });
		tot += c*m;
	}
	sort(edges.begin(), edges.end());
	for (auto e : edges) {
		int a = e.second.second.first,
			b = e.second.second.second;
		ll c = e.first;
		if (e.second.first) {
			int pa = findn(a),
				pb = findn(b);
			if (pa == pb)continue;
			tot -= c*dc;
			djn[pa] = djn[pb];
			dp--;
		}
		else {
			int pa = findm(a),
				pb = findm(b);
			if (pa == pb)continue;
			tot -= c*dp;
			djm[pa] = djm[pb];
			dc--;
		}
	}
	printf("%lld\n", tot);
	cin >> tot;
}