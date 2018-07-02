#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 50

string mp[MAXN];
int v[MAXN][MAXN];
int idx = 1;
int n, m;
void dfs(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m)
		return;
	if(mp[x][y] != ' ')
		return;
	if(v[x][y])
		return;
	v[x][y] = idx;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}


#define MAXF 10000
#define INF 34983245

int adj[MAXF][MAXF];
int nd[MAXF][MAXF];

void mkcon(int a, int b, int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m)
		return;
//		printf("%d,%d -> %d,%d\n",a,b,x,y);
	if(nd[a][b] && v[x][y])
//        printf(" %d -> %d\n",nd[a][b] + 1,v[x][y] ),
		adj[nd[a][b] + 1][v[x][y]] = INF;
	if(nd[a][b] && nd[x][y])
//        printf(" %d -> %d\n", nd[a][b] + 1,nd[x][y]),
		adj[nd[a][b] + 1][nd[x][y]] = INF;
	if(v[a][b] && nd[x][y])
//        printf(" %d -> %d\n",v[a][b],nd[x][y] ),
		adj[v[a][b]][nd[x][y]] = INF;
}

int p[MAXF];

int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src, INF });
	while (!q.empty()) {
		pii i = q.front();
		q.pop();
		if (i.first == dst)
			return i.second;
		for (int j = 0; j < idx; j++)
			if (adj[i.first][j] > 0)
				if (p[j] == -1)
					p[j] = i.first,
						   q.push({ j, min(i.second, adj[i.first][j]) });
	}
	return -1;
}

int karp(int src, int dst) {
	int res = 0;
	while (true) {
		int af = bfs(src, dst);
		if (af <= 0)
			break;
		res += af;
		int cur = dst;
		while (cur != src) {
			int par = p[cur];
			adj[par][cur] -= af;
			adj[cur][par] += af;
			cur = par;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ws(cin);
	for(int i = 0; i < n; i++)
		getline(cin, mp[i]);

	int src, dst;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(mp[i][j] == ' ') {
				if(!v[i][j])
					dfs(i, j), idx++;
			} else if(mp[i][j] == 'N')
				src = nd[i][j] = idx, idx+=2;
			else if(mp[i][j] == 'F')
				dst = nd[i][j] = idx, idx+=2;
			else if(mp[i][j] == 'P')
				nd[i][j] = idx, adj[idx][idx + 1] = 1, idx += 2;

	for(int x = 0; x < n; x++)
		for(int y = 0; y < m; y++) {
			mkcon(x, y, x + 1, y);
			mkcon(x, y, x - 1, y);
			mkcon(x, y, x, y + 1);
			mkcon(x, y, x, y - 1);
		}

	printf("%d", karp(src+1, dst));
}
