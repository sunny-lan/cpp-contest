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
using namespace std;

#define memeset memset
#define INF(a) (a==-1?INT_MAX:a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500000

vector<pii> adj[MAXN];
bool special[MAXN];
bool visited[MAXN];

ll da[MAXN];
ll db[MAXN];

ll nv[MAXN];

int deg[MAXN];

int main() {
	queue<int> q;
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		a--, b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		deg[a]++, deg[b]++;
	}
	int a;
	for (int i = 0; i < k; i++) {
		int t; scan(t);
		t--;
		special[t] = true;
		a = t;
	}

	for (int i = 0; i < n; i++)if (!special[i] && deg[i] == 1)
		q.push(i);

	while (!q.empty()) {
		int i = q.front(); q.pop();
		deg[i]--;
		for (auto neigh : adj[i]) {
			int j = neigh.first;
			if (deg[j] == 0)continue;
			deg[j]--;
			if (deg[j] == 1 && !special[j])
				q.push(j);
		}
	}

	ll tot = 0;

	int u; ll maxi = -1;
	q.push(a);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (visited[i])continue;
		visited[i] = true;
		if (special[i] && da[i] > maxi)
			maxi = da[i], u = i;
		for (auto neigh : adj[i])if (!visited[neigh.first]) {
			int j = neigh.first;ll d = neigh.second;
			nv[j] = nv[i] + d;
			da[j] = da[i] + d;
			if (deg[j] != 0)tot += d, nv[j] = 0;
			q.push(neigh.first);
		}
	}

	int v; maxi = -1;
	q.push(u);
	memeset(da, 0, sizeof da);
	memeset(visited, false, sizeof visited);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (visited[i])continue;
		visited[i] = true;
		if (special[i] && da[i] > maxi)
			maxi = da[i], v = i;
		for (auto neigh : adj[i])if (!visited[neigh.first]) if (neigh.first != i)
			da[neigh.first] = da[i] + neigh.second, q.push(neigh.first);
	}

	q.push(v);
	memeset(visited, false, sizeof visited);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (visited[i])continue;
		visited[i] = true;
		for (auto neigh : adj[i])if (!visited[neigh.first]) if (neigh.first != i)
			db[neigh.first] = db[i] + neigh.second, q.push(neigh.first);
	}

	for (int i = 0; i < n; i++) {
		ll d = max(da[i], db[i]);
		printf("%lld\n", 2 * (tot - (d - nv[i])) + d);
	}
	cin >> n;
}