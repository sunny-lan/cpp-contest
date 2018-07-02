#include<bits/stdc++.h>
using namespace std;

#define MAXN 100001

int u[MAXN];
vector<int> adj[MAXN];
int h;
int v[MAXN];
int fil;
int ans[MAXN];
int dfs(int i) {
	v[i] = fil;
//    cout << "dfs("<<i<<endl;
	int res = 1;
	for(int k : adj[i]) {
		if(v[k] == fil) {
//                cout << " col "<<(u[k] + 1)%h<< " vs "<<(u[i] + 1)%h  <<endl;
			if((u[k] + 1)%h == (u[i] + 1)%h)
				return 1 << 30;
		}
		else
//			printf(" chk %d\n", k),
				   res = min(1 << 30, res + dfs(k));
	}
//	cout << "ans " << i << " = " << res << endl;
	ans[i] = res;
	return res;
}

int main() {
//	memset(dp, -1, sizeof dp);

	int n, m;
	scanf("%d %d %d", &n, &m, &h);
	for(int i = 0; i < n; i++)
		scanf("%d", &u[i]);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a,  &b);
		a--, b--;
		if((u[a] + 1) % h == u[b])
//			printf("%d -> %d\n", a, b),
				   adj[a].push_back(b);
		if((u[b] + 1) % h == u[a])
//			printf("%d -> %d\n", b, a),
				   adj[b].push_back(a);
	}

	int mini = INT_MAX, best;
	for(int i = 0; i < n; i++) {
		if(v[i] == 0) {
			fil = i + 1;
			dfs(i);
		}
		if(ans[i] < mini)
            mini = ans[i], best = i;
	}

//	cout << "b"<<best<<endl;

	printf("%d\n", mini);

	memset(v, 0, sizeof v);
	fil=6587326;
	dfs(best);

	for(int i = 0; i < n; i++)
		if(v[i] == 6587326)
			printf("%d ", i + 1);
}
