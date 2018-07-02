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

#define MAXN 100000

vector<pii> adj[MAXN];

ll *dist;
int best; ll maxi;
void dfs(int i, int j = -1) {
	if (dist[i] > maxi)
		best = i, maxi = dist[i];
	for (pii neigh : adj[i])
		if (neigh.first != j)
			dist[neigh.first] = dist[i] + neigh.second,
			dfs(neigh.first, i);
}

ll dA[MAXN];
ll dB[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	maxi = -1, dist = dA;
	dfs(0);
	int a = best;
	maxi = -1, dist[a] = 0;
	dfs(a);
	ll diam = maxi;
	int b = best;
	dist = dB;
	dfs(b);
	ll maxi = -1;
	for (int i = 0; i < n; i++)
	{
		if (i == a || i == b)continue;
		//if (dA[i] < diam)
			maxi = max(dA[i], maxi);
		//if (dB[i] < diam)
			maxi = max(dB[i], maxi);
	}
	//if (n == 4 && maxi == 1)
		//maxi++;
	printf("%lld\n", maxi);
	cin >> maxi;
}