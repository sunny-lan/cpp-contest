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

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 420

int N;
vector<int> adj[MAXN];

bool cut[MAXN];
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int vtime = 0;
void _cut_dfs(int i, int j = -1) {
	if (visited[i])return;
	visited[i] = true;
	disc[i] = low[i] = ++vtime;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			_cut_dfs(neigh, i);
			low[i] = min(low[i], low[neigh]);
			if (j != -1 && low[neigh] >= disc[i])
				cut[i] = true;
		}
	}
	if (j == -1 && cnt > 1)
		cut[i] = true;
}

void cutnodes() {
	// if called more than once, visited must be memset to false
	for (int i = 0; i<N; i++)if (!visited[i])_cut_dfs(i);
}

int visited2[MAXN];
int labelled[MAXN];
int label;
void dfs(int i) {
	if (visited2[i])return;
	visited2[i] = label;
	for (int j : adj[i]) dfs(j);
}

int sz[MAXN];
int cnt[MAXN];

unordered_map<int, int> cust;
int gt(int y) {
	if (cust.find(y) != cust.end())
		return cust[y];
	return cust[y] = N++;
}

int main() {
	int T;
	while (true) {
		scan(T);
		if (T == 0)break;

		cust.clear();
		N = 0;
		for (int i = 0; i < MAXN; i++)adj[i].clear();
		memset(cut, 0, sizeof cut);
		memset(sz, 0, sizeof sz);
		memset(cnt, 0, sizeof cnt);

		for (int i = 0; i < T; i++) {
			int s, t; scan(s); scan(t);
			s = gt(s), t = gt(t);
			adj[s].push_back(t);
			adj[t].push_back(s);
		}

		memset(visited, false, sizeof visited);
		for (int i = 0; i<N; i++)if (!visited[i])_cut_dfs((i+1)%N);

		for (int i = 0; i < N; i++)
			if (cut[i])
				visited2[i] = -1;
			else
				visited2[i] = 0;
		
		for (int i = 0; i < N; i++) {
			label = i + 1;
			dfs(i);
		}

		for (int i = 0; i < N; i++)
			if (visited2[i] > 0)
				sz[visited2[i]]++;
		memcpy(labelled, visited2, sizeof labelled);

		label = -1;
		for (int i = 0; i < N; i++)if (cut[i]) {
			for (int i = 0; i < N; i++)
				if (cut[i])
					visited2[i] = -1;
				else
					visited2[i] = 0;
			for (int j : adj[i])if (visited2[j] == 0) {
				cnt[labelled[j]]++;
				dfs(j);
			}
		}

		ull cmb = 1ull;
		int tot = 0;
		int num = 0;
		ll lol = 0;
		for (int i = 1; i <= N; i++)if (sz[i] > 0) {
			num++;
			if (cnt[i] <= 1) {
				tot++;
				cmb *= (unsigned long long)sz[i];
			}
			lol = (sz[i] * (sz[i] - 1)) / 2;
		}

		if (num == 1)
			printf("2 %lld\n", lol);
		else
			printf("%d %llu\n", tot, cmb);
	}
}