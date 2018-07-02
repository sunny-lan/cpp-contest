#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef int ll;

#define MAXN 200001

vector<pair<int, ll>> adj[MAXN];
bool visited[MAXN];

int deg[MAXN];

ll dA[MAXN];
ll dB[MAXN];

ll* tmp;//current array to fill with distances
ll tmp2[MAXN];

//returns furthest node, dist is stored in currArr
int dfs(int i, int j, ll lvl) {
	tmp[i] = lvl;
	ll ret = i;
	ll max = lvl;
	for (auto neigh : adj[i]) {
		if (neigh.first != j) {
			ll alt = dfs(neigh.first, i, lvl + neigh.second);
			if (tmp[alt] > max) {
				max = tmp[alt];
				ret = alt;
			}
		}
	}
	tmp2[i] = max;
	return ret;
}
int main() {
	memset(dA, 0, sizeof dA);
	memset(dB, 0, sizeof dB);
	int n, t; scan(n); scan(t);
	int tot = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; int c; scan(a); scan(b); scan(c);
		a--, b--;
		adj[a].push_back({ b,c }), deg[a]++;
		adj[b].push_back({ a,c }), deg[b]++;
		tot += c;
	}

	tmp = dA;
	int u = dfs(0, -1, 0);
	memset(dA, 0, sizeof dA);
	int v = dfs(u, -1, 0);
	tmp = dB;
	dfs(v, -1, 0);

	for (int i = 0; i < n; i++)
		if (deg[i] == t) {
			ll path = max(dA[i], dB[i]);
			printf("%d %d\n", i + 1, (tot - path) * 2 + path);
		}
	cin >> n;
}