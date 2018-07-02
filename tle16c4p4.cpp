#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

#define MAXN 100000

bool visited[MAXN];
int src[MAXN];
ll sdist[MAXN];
vector<pair<ll, int>> adj[MAXN];

bool val;

pair<ll, int> dfs(int i, int j) {
	pair<ll, int> best = { 0, i };
	visited[i] |= val;
	src[i] = j;
	for (auto neigh : adj[i]) {
		if (neigh.first == j)continue;
		auto res = dfs(neigh.first, i);
		res.first += neigh.second;
		if (res.first > best.first)
			best = res;
	}
	sdist[i] = best.first;
	return best;
}

int main() {
	int n, m, q; scan(n); scan(m); scan(q);
	for (int i = 0; i < m; i++)
	{
		int u, v, l; scan(u); scan(v); scan(l);
		u--, v--;
		adj[u].push_back({ v , l });
		adj[v].push_back({ u , l });
	}

	if (q == 1) {
		ll tot = 0;
		for (int i = 0; i < n; i++)
			if (!visited[i]) {
				val = false;
				int a = dfs(i, -1).second;
				val = true;
				tot += dfs(a, -1).first + 1;
			}
		cout << tot - 1 << endl;
	}
	else {
		ll nextmax = 0;
		ll currmax = 0;
		for (int i = 0; i < n; i++)
			if (!visited[i]) {
				val = false;
				int a = dfs(i, -1).second;
				val = true;
				auto res = dfs(a, -1);
				int curr = res.second;
				ll tmp = 10e20;
				while (curr != -1) {
					tmp =min(tmp, max(sdist[curr], res.first - sdist[curr]));
					curr = src[curr];
				}
				if (tmp >= currmax)
				{
					nextmax = currmax;
					currmax = tmp;
				}
			}
		cout << max(nextmax + 1, currmax) << endl;
	}
}