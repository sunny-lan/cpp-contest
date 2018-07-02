#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100

vector<pii> adj[MAXN];

int dp[MAXN][MAXN][27][2];
int f(int a, int b, int c = 0, int d = 0) {
	int &res = dp[a][b][c][d];
	if(res != -1)
		return res;
	if(d) {
		res = 1;
		for(pii k : adj[b])
			if(k.s >= c)
				if(f(a, k.f,  k.s, 0) == 0) {
					res=0;
					break;
				}
	}else{
	    res = 0;
		for(pii k : adj[a])
			if(k.s >= c)
				if(f(k.f, b, k.s, 1) == 1) {
					res=1;
					break;
				}
	}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int v, u;
		char c;
		scanf("%d %d %c", &v, &u, &c);
		v--, u--;
		int k = c - 'a' + 1;
		adj[v].push_back({u, k});
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf(f(i, j) ? "A" : "B");
		printf("\n");
	}
}
