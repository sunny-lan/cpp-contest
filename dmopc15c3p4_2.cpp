#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <functional>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define MAXN 3001

ll x[MAXN], y[MAXN];

ll dst(int u, int v) {
	ll dx = x[u] - x[v],
		dy = y[u] - y[v];
	return dx*dx + dy*dy;
}

int n, src, q;
bool inq[MAXN];
ll du[MAXN];

void dij() {
	memset(inq, false, sizeof inq);
	du[src] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({ 0,src });
	while (!q.empty()) {
		int curr = q.top().second; q.pop();
		inq[curr] = false;
		for (int neigh = 0; neigh < n; neigh++)
		{
			ll alt = dst(neigh, curr) + du[curr];
			if (alt < du[neigh]) {
				du[neigh] = alt;
				if (!inq[neigh]) {
					q.push({ alt, neigh });
					inq[neigh] = true;
				}
			}
		}
	}
}

#define MAXQ 1000000
pli qu[MAXQ];
int ans[MAXQ];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &x[i], &y[i]), du[i]=1ll<<55;

	scanf("%d %d", &src, &q);
	src--;

	dij();

	for (int i = 0; i < q; i++)
		scanf("%lld", &qu[i].first), qu[i].second = i;

	sort(qu, qu + q);
	sort(du, du + n);

	int j = 0;
	for (int i = 0; i < q; i++) {
		while (j<n && du[j] <= qu[i].first)
			j++;
		ans[qu[i].second] = j;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	cin >> n;
}