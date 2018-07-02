#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 405;
ll adj[N][N], dist[N];
int n, c, K;
bool v[N];
int vl[N];
void sp(int src) {
	memset(dist, 0x3f, sizeof dist);
	dist[src] = 0;
	while(1) {
		int idx = -1;
		for(int i = 0; i < n; ++i) {
			if(!v[i] && (idx == -1 || dist[i] < dist[idx]))
				idx = i;
		}
		if(idx == -1)
			break;
		v[idx] = 1;
		for(int i = 0; i < n; ++i) {
			if(!v[i] && adj[idx][i] != -1 && dist[idx] + adj[idx][i] < dist[i])
				dist[i] = dist[idx] + adj[idx][i];
		}
	}
}
vector<int> cls[N];
int main() {
	memset(adj, -1, sizeof adj);
	scanf("%d%d%d", &n, &c, &K);
	for(int i = 0; i < n; ++i)
		scanf("%d", &vl[i]);
	for(int i = 0; i < n; ++i) {
		int clas;
		scanf("%d", &clas);
		for(int j = 0; j < clas; ++j) {
			int x;
			scanf("%d", &x);
			cls[--x].pb(i);
		}
	}
	for(int i = 0; i < c; ++i) {
		for(int j = 0; j < cls[i].size(); ++j) {
			for(int k = j + 1; k < cls[i].size(); ++k) {
				int x = cls[i][j], y = cls[i][k];
				adj[x][y] = abs(vl[x] - vl[y]) + K;
				adj[y][x] = abs(vl[x] - vl[y]) + K;
			}
		}
	}
	sp(0);
	for(int i = 0; i < n; ++i)
		printf("%lld\n", dist[i] < 0x3f3f3f3f3f3f3f3fLL ? dist[i] : -1LL);
	return 0;
}
