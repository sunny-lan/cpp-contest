#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 200010

vector<pii> adj[MAXN];

bool v[MAXN];
int sz[MAXN];
int cfs(int i, int j = -1) {
	if(v[i])
		return 0;
	sz[i] = 1;
	for(pii neigh : adj[i])
		if(neigh.first != j)
			sz[i] += cfs(neigh.first, i);
	return sz[i];
}

int centroid(int i, int tsz, int j = -1) {
	for(pii neigh : adj[i])
		if(neigh.first != j && !v[neigh.first] && sz[neigh.first] * 2 > tsz)
			return centroid(neigh.first, tsz, i);
	return i;
}

int k;
int ans = INT_MAX;
int pth[1000001];
int dirty[1000001];
int idx = 0;
vector<pii> vals;
void dfs(int i, int j, int dst, int len) {
	if(v[i])
		return;
	if(dst <= k && len < ans) {
		if(dirty[k - dst] == idx)
			ans = min(ans, len + pth[k - dst]);
		vals.push_back({dst, len});
		for(pii neigh : adj[i])
			if(neigh.first != j)
				dfs(neigh.first, i, dst + neigh.second, len + 1);
	}
}

void calc(int i = 0) {
	if(v[i])
		return;
	i = centroid(i, cfs(i));
	v[i] = true;
	idx++;
	for(pii neigh : adj[i])
		if(!v[neigh.first]) {
			vals.clear();
			dfs(neigh.first, i, neigh.second, 1);
			for(pii x : vals)
			{
				int alt = min(dirty[x.first] == idx ? pth[x.first] : INT_MAX, x.second);
				pth[x.first] = alt;
				dirty[x.first] = idx;
			}
		}
	if(dirty[k] == idx)
		ans = min(ans, pth[k]);
	for(pii neigh : adj[i])
		calc(neigh.first);
}

int best_path(int N, int K, int H[][2], int L[]) {
	k = K;
	for(int i = 0; i < N - 1; i++) {
		int a = H[i][0], b = H[i][1];
		adj[a].push_back({b, L[i]});
		adj[b].push_back({a, L[i]});
	}
	calc();
	return ans == INT_MAX ? -1 : ans;
}
