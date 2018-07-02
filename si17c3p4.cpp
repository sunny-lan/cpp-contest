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

#define MAXN 10000

vector<int> adj[MAXN];

int deg[MAXN];

int label[MAXN];
int idx = 0;
void dfs(int i) {
	if (!label[i])return;
	if (deg[i] > 2) {
		label[i] = -1;

	}
	else {
		label[i] = idx;
		for (int j : adj[i])
			dfs(j);
	}
}

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		deg[a]++, deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}