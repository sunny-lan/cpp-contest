#include <bits/stdc++.h>
#include"factories.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 500000

vector<pii> adj[MAXN];

int sz[MAXN];
int v[MAXN];
int cfs(int i, int j = -1) {
	if(v[i])
		return 0;
	sz[i] = 1;
	for(pii k : adj[i])
		if(k.first != j)
			sz[i] += cfs(k.first, i);
	return sz[i];
}

int centroid(int tsz, int i, int j = -1) {
	for(pii k : adj[i])
		if(!v[k.first] && k.first != j && sz[k.first] * 2 > tsz)
			return centroid(tsz, k.first, i);
	return i;
}

unordered_map<int, ll> dsts[MAXN];
int ct;
void dfs(ll dst, int i, int j = -1) {
	if(v[i])
		return;
	dsts[ct][i] = dst;
	for(pii k : adj[i])
		if(k.first != j)
			dfs(dst + k.second, k.first, i);
}

int cp[MAXN];

void preproc(int i, int j = -1) {
	i = centroid(cfs(i), i);
	cp[i] = j;
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
	preproc(0);
}

int idx = 0;
int dirty[MAXN];
ll mini[MAXN];

ll gmin(int i){
    if(dirty[i]==idx)return mini[i];
    return 1ll<<40;
}

ll Query(int S, int X[], int T, int Y[]) {
    idx++;
    for(int i=0;i<S;i++){
        int tmp=X[i];
        while(tmp!=-1)
        {
            mini[tmp]=min(gmin(tmp), dsts[tmp][X[i]]);
            tmp=cp[tmp];
        }
    }

    ll res=1ll<<40;
    for(int i=0;i<T;i++){
        int tmp=Y[i];
        while(tmp!=-1)
        {
            res=min(gmin(tmp)+dsts[tmp][Y[i]], res);
            tmp=cp[tmp];
        }
    }
    return res;
}
