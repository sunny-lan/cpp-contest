#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001

vector<int> adj[MAXN];
int low[MAXN];
int disc[MAXN];
bool v[MAXN];
int ct = 0;
stack<int> s;
int comp[MAXN];
int sz[MAXN];
bool ins[MAXN];

void dfs(int i) {
	v[i] = true;
	low[i] = disc[i] = ct++;
	s.push(i);
	ins[i] = true;
	for(int k : adj[i])
		if(v[k]) {
			if(ins[k])
				low[i] = min(low[i], disc[k]);
		} else
			dfs(k),
				low[i] = min(low[i], low[k]);
	if(low[i] == disc[i])
	{
		int cur;
		do {
			cur = s.top();
			ins[cur] = false;
			s.pop();
			comp[cur] = i;
			sz[i]++;
		} while(cur != i);
	}
//	disc[i] = INT_MAX;
}

int n, m, q;
void tarjan() {
	for(int i = 0; i < n; i++)
		if(!v[i])
			dfs(i);
}

vector<int> madj[MAXN];
int dp[MAXN][MAXN];

int f(int a, int b) {
	if(a == b)
		return 0;
	int &res = dp[a][b];
	if(res != -1)
		return res;
	res = -666666666;
	for(int k : madj[b])
		res = max(res, f(a, k));
	res += sz[b];
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < m; i++) {
//            cout << "pls enter "<<i<<" : "<<endl;
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
	}
	tarjan();

//	for(auto xd : comp)
//		cout << xd.first << ": " << xd.second << endl;

	for(int a = 0; a < n; a++)
		for(int b : adj[a]) {
			int ca = comp[a], cb = comp[b];
			if(ca == cb)
				continue;
//            cout << cb<<" -> "<<ca<<endl;
			madj[cb].push_back(ca);
		}

	for(int i = 0; i < q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int cx = comp[x - 1], cy = comp[y - 1];
//		cout <<"re"<< cx<<" "<<cy<<endl;
		if(cx == cy) {
			printf("Indeterminate\n");
			continue;
		}

		if(f(cx, cy) >= 0) {
//                while(f(cx, cy) - sz[cy]<0)printf("0");
			printf("%d %d\n", x, f(cx, cy) - sz[cy]);
			continue;
		}

		if(f(cy, cx) >= 0) {
//                while(f(cy, cx) - sz[cx]<0)printf()
			printf("%d %d\n", y, f(cy, cx) - sz[cx]);
			continue;
		}
		printf("Indeterminate\n");
	}
}
