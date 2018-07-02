#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef pair<int, int> pii;

#define MAXN 2000

char map[MAXN][MAXN];

vector<pii> adj[MAXN][MAXN];

int deg[MAXN][MAXN];

int n, m;

int main() {
	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &map[i][j]);

	//north pass
	for (int j = 0; j < m; j++) {
		int lastIdx = 0;
		for (int i = 0; i < n; i++)
			if (map[i][j] == 'N')
				for (int k = lastIdx; k < i; k++)
					if (map[k][j] != '.') {
						adj[k][j].push_back({ i,j });
						deg[i][j]++;
						lastIdx = i;
					}
	}

	//south pass
	for (int j = 0; j < m; j++) {
		int lastIdx = n - 1;
		for (int i = n - 1; i >= 0; i--)
			if (map[i][j] == 'S')
				for (int k = lastIdx; k > i; k--)
					if (map[k][j] != '.') {
						adj[k][j].push_back({ i,j });
						deg[i][j]++;
						lastIdx = i;
					}
	}

	//west pass
	for (int i = 0; i < n; i++) {
		int lastIdx = 0;
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'W')
				for (int k = lastIdx; k < j; k++)
					if (map[i][k] != '.') {
						adj[i][k].push_back({ i,j });
						deg[i][j]++;
						lastIdx = j;
					}
	}

	//east pass
	for (int i = 0; i < n; i++) {
		int lastIdx = m - 1;
		for (int j = m - 1; j >= 0; j--)
			if (map[i][j] == 'E')
				for (int k = lastIdx; k > j; k--)
					if (map[i][k] != '.') {
						adj[i][k].push_back({ i,j });
						deg[i][j]++;
						lastIdx = j;
					}
	}


	queue<pii> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (map[i][j] != '.')
			if (deg[i][j] == 0)
				q.push({ i,j });

	while (!q.empty()) {
		pii next = q.front(); q.pop();
		printf("(%d,%d)\n", next.first, next.second);

		for (pii neigh : adj[next.first][next.second]) {
			deg[neigh.first][neigh.second]--;
			if (deg[neigh.first][neigh.second] == 0)
				q.push(neigh);
		}
	}

	cin >> n;
}