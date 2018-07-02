#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 500

vector<int> adj[MAXN];

int deg[MAXN];

int u[MAXN], v[MAXN];

int dis;

int dp[MAXN];
int f(int i) {
	int res = dp[i];
	if (res != -1)return res;
	dp[i] = -2;
	res = 1;
	for (int j : adj[i])
	{
		if (i == u[dis] && j == v[dis])continue;
		if (f(j) == -2) {
			res = -2;
			break;
		}
	}
	return dp[i] = res;
}


int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u[i], &v[i]);
		u[i]--, v[i]--;
		deg[v[i]]++;
		adj[u[i]].push_back(v[i]);
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int i = q.front(); q.pop();
		deg[i]--;
		for (int j : adj[i])
		{
			deg[j]--;
			if (deg[j] == 0)q.push(j);
		}
	}

	for (dis = 0; dis < m; dis++)
		if (deg[v[dis]] == 1) {
			memset(dp, -1, sizeof dp);
			for (int i = 0; i < n; i++)
				if (deg[i] > 0)
					if (f(i) == -2)
						goto outer;
			printf("YES");
			goto end;
		outer:continue;
		}
	printf("NO");
end:
	cin >> n;
}