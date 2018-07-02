#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 500000

vector<int> adj[MAXN];

int dA[MAXN];
int dB[MAXN];

int* tmp;//current array to fill with distances
int tmp2[MAXN];

//returns furthest node, dist is stored in currArr
int dfs(int i, int j, int lvl) {
	tmp[i] = lvl;
	int ret = i;
	int max = lvl;
	for (int neigh : adj[i]) {
		if (neigh != j) {
			int alt = dfs(neigh, i, lvl + 1);
			if (tmp[alt] > max) {
				max = tmp[alt];
				ret = alt;
			}
		}
	}
	tmp2[i] = max;
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	tmp = dA;
	int a = dfs(0, -1, 0);
	int b = dfs(a, -1, 0);
	tmp = dB;
	dfs(b, -1, 0);
	for (int i = 0; i < n; i++)
		cout << max(dA[i]+1, dB[i]+1) << endl;
}