#define _CRT_SECURE_NO_WARNINGS

#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 2001
#define MAXK 210

vector<pair<int, pii>> adj[MAXN];

int inq[MAXN];
int du[MAXN][MAXK];

int main() {
	memset(du, 0x3f, sizeof du);
	int k, n, m; scanf("%d %d %d", &k, &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, t, h; scanf("%d %d %d %d", &a, &b, &t, &h);
		a--, b--;
		adj[a].push_back({ b,{t,h} });
		adj[b].push_back({ a,{ t,h } });
	}
	int a, b; scanf("%d %d", &a, &b);
	a--, b--;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	du[a][0] = 0;
	q.push({ 0, a });
	inq[a] = true;
	while (!q.empty()) {
		int i = q.top().second; q.pop();
		inq[i] = false;
		for (auto neigh : adj[i]) {
			int j = neigh.first;
			pii cust = neigh.second;
			for (int l = 0; l + cust.second < k; l++) {
				int alt = du[i][l] + cust.first;
				if (alt < du[j][l + cust.second]) {
					du[j][l + cust.second] = alt;
					if (!inq[j]) {
						inq[j] = true;
						q.push({ alt, j });
					}
				}
			}
		}
	}

	int mini = INT_MAX;
	for (int i = 0; i < k; i++)
		mini = min(du[b][i], mini);
	if (mini >= 0x3f3f3f3f)
		mini = -1;
	printf("%d\n", mini);
	cin >> mini;
}