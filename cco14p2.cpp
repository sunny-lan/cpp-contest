#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;


//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define INF (1ll<<50)
#define MAXN 100010

vector<pil> *adj;
vector<pil> adjF[MAXN];
vector<pil> adjB[MAXN];
struct edge {
	int x, y; ll d, c, l;
};
edge edges[MAXN];
bool pred(const edge& a, const edge& b) {
	return a.d < b.d;
}
bool pred2(const ll& a, const edge& b) {
	return a < b.d;
}

ll *dp;
ll distB[MAXN];
ll distA[MAXN];

bool inq[MAXN];

void f(int src) {
	memset(inq, false, sizeof inq);
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({ 0, src });
	dp[src] = 0;
	while (!q.empty()) {
		int curr = q.top().second;
		ll dist = dp[curr];
		inq[curr] = false;
		q.pop();
		for (pil neigh : adj[curr]) {
			int j = neigh.first;
			ll alt = dist + neigh.second;
			if (alt < dp[j]) {
				dp[j] = alt;
				if (!inq[j]) {
					q.push({ alt, j });
					inq[j] = true;
				}
			}
		}
	}
}

ll psa[MAXN];

int main() {
	int n, m, a, b; scan(n); scan(m); scan(a); scan(b);
	for (int i = 0; i < n; i++)
		distA[i] = distB[i] = INF;
	a--, b--;
	for (int i = 0; i < m; i++) {
		scan(edges[i].x); scan(edges[i].y); scan(edges[i].l); scan(edges[i].c);
		edges[i].x--, edges[i].y--;
		adjF[edges[i].x].push_back({ edges[i].y,edges[i].l });
		adjB[edges[i].y].push_back({ edges[i].x,edges[i].l });
	}
	dp = distA, adj = adjF;
	f(a);
	dp = distB, adj = adjB;
	f(b);
	for (int i = 0; i < m; i++) {
		edge &e = edges[i];
		e.d = distA[e.x] + e.l + distB[e.y];
	}
	sort(edges, edges + m, pred);

	for (int i = 0; i < m; i++)
		psa[i + 1] = psa[i] + edges[i].c;
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		ll d; scan(d);
		printf("%lld\n", psa[upper_bound(edges, edges + m, d, pred2) - edges]);
	}
	cin >> q;
}