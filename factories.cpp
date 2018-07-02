#include <bits/stdc++.h>
#include"factories.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 500000

vector<pii> adj[MAXN];

int sz[MAXN];
int v[MAXN];
inline int cfs(int i, int j = -1) {
	sz[i] = 1;
	for(pii k : adj[i])
		if(!v[k.first] && k.first != j)
			sz[i] += cfs(k.first, i);
	return sz[i];
}

inline int centroid(int tsz, int i, int j = -1) {
	for(pii k : adj[i])
		if(!v[k.first] && k.first != j && sz[k.first] * 2 > tsz)
			return centroid(tsz, k.first, i);
	return i;
}

vector<pair<int, ll>> dsts[MAXN];
int ct;
inline int dfs(ll dst, int i, int j = -1) {
	sz[i] = 1;
	dsts[i].push_back({ct, dst});
	for(pii k : adj[i])
		if(!v[k.first] && k.first != j)
			sz[i] += dfs(dst + k.second, k.first, i);
	return sz[i];
}

inline void preproc(int i, int j = -1) {
	i = centroid(sz[i], i);
	ct = i;
	dfs(0, i);
	v[i] = true;
	for(pii k : adj[i])
		if(!v[k.first])
			preproc(k.first, i);
}

 void Init(int N, int A[], int B[], int D[]) {
	for(int i = 0; i < N - 1; i++)
	{
		adj[A[i]].push_back({B[i], D[i]});
		adj[B[i]].push_back({A[i], D[i]});
	}
	cfs(0);
	preproc(0);
}

int idx = 0;
int dirty[MAXN];
ll mini[MAXN];

const ll inf = 1ll << 60;

 ll Query(int S, int X[], int T, int Y[]) {
	idx++;
	for(int i = 0; i < S; i++) {
		for(auto par : dsts[X[i]])
		{
			const int k = par.first;
			mini[k] = min((dirty[k] == idx ? mini[k] : inf), par.second);
			dirty[k] = idx;
		}
	}

	ll res = inf;
	for(int i = 0; i < T; i++) {
		for(auto par : dsts[Y[i]])
		{
			const int k = par.first;
			res = min((dirty[k] == idx ? mini[k] : inf) + par.second, res);
		}
	}
	return res;
}
