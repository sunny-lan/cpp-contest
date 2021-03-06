#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 200000

vector<int> adj[MAXN];

bool cut[MAXN];
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int time = 0;
void dfs(int i, int j = -1) {
	if (visited[i])return;
	visited[i] = true;
	disc[i] = low[i] = ++time;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			dfs(neigh, i);
			low[i] = min(low[i], low[neigh]);
			if (j != -1 && low[neigh] >= disc[i])
				cut[i] = true;
		}
	}
	if (j == -1 && cnt > 1)
		cut[i] = true;
}

int deg[MAXN];

int comp[MAXN];

int fl;

void fil(int i) {
	if (comp[i])return;
	comp[i] = fl;
	for (int nei : adj[i])
		fil(nei);
}

bool cust1[MAXN], cust2[MAXN];


int main() {
	int n, m; scan(n); scan(m);
	int eidx = n;
	for (int i = 0; i < m; i++) {
		int u, v; scan(u); scan(v);
		u--, v--;
		int ething = eidx++;
		adj[u].push_back(ething);
		adj[ething].push_back(v);
		deg[v]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (deg[i] == 0 && !visited[i])
			dfs(i);

	
}