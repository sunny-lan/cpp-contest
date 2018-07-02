#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 500000

//vector<int> adj[MAXN];

vector<int> c[MAXN];
int p[MAXN];


int df[MAXN];
int dg[MAXN];

int f(int i) {
	int res = df[i];
	if (res != -1)
		return res;

	res = 0;

	for (int neigh : c[i])
		res = max(res, f(neigh));

	df[i] = ++res;
	return res;
}

int g(int i) {
	int res = dg[i];
	if (res != -1)
		return res;

	res = 0;

	if (i == 0) {
		res = f(i);
	} else {
		if (p[i] == 0) {
			for (int neigh : c[0])
				if (neigh != i)
					res = max(res, f(neigh));
			res += 2;
		} else {
			res = g(p[i]) + 1;

			for (int neigh : c[p[i]])
				if (neigh != i)
					res = max(res, f(neigh) + 2);
		}
	}
	dg[i] = res;
	return res;
}

//void dfs(int i, int j) {
//	p[i] = j;
//	for (int neigh : adj[i])
//		if (neigh != j) {
//			c[i].push_back(neigh);
//			dfs(neigh, i);
//		}
//}


int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		c[u].push_back(v);
		//c[v].push_back(u);
		p[v] = u;
		dg[i] = -1;
		df[i] = -1;
	}
	dg[n - 1] = -1;
	df[n - 1] = -1;
	//dfs(0, -1);
	for (int i = 0; i < n; i++)
		cout << max(f(i), g(i)) << endl;
}