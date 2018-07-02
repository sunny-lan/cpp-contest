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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

vector<pii> adj[MAXN];

pii du[MAXN];
bool visited[MAXN];
bool inq[MAXN];

typedef pair<pii, int> cust;

int main() {
	memset(du, -1, sizeof du);

	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		a--, b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	pii inf = { -1,-1 };

	du[0] = { 0,0 };

	priority_queue<cust, vector<cust>, greater<cust>> q;
	q.push({ {0,0}, 0 });

	while (!q.empty()) {
		cust curr = q.top(); q.pop();
		int node = curr.second;
		if (du[node] != inf && curr.first > du[node])continue;
		visited[node] = true;
		for (auto neigh : adj[node]) {
			int j = neigh.first;
			if (visited[j])continue;

			pii alt = { curr.first.first + neigh.second, curr.first.second + 1 };

			if (du[j] == inf || alt < du[j]) {
				du[j] = alt;
				q.push({ alt,j });
			}
		}
	}
	if (du[n - 1].first == -1)
		printf("-1\n");
	else 	printf("%d %d\n", du[n - 1].first, du[n - 1].second);
}