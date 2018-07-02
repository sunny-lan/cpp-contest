#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
list<int> adj[5000];
int toIdx[5000], toLabel[5000], p[5000], dep[5000];
void dfs(int n, int d) {
	dep[n] = d;
	for (int i : adj[n])
		dfs(i, d + 1);
}
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		p[b] = a;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
		toIdx[i] = i, toLabel[i] = i;
	dfs(0, 0);
	for (int i = 0; i < q; ++i) {
		int cmd, a, b;
		scanf("%d\n", &cmd);
		if (cmd == 1) {
			scanf("%d %d", &a, &b);
			int cur = toIdx[a];
			int prev = a;
			for (int i = 0; i < b; ++i) {
				cur = p[cur];
				toIdx[toLabel[cur]] = prev;
				toLabel[prev] = toLabel[cur];
				prev = cur;
			}
			toIdx[a] = cur;
			toLabel[cur] = a;
		}
		else {
			scanf("%d", &a);
			printf("%d\n", dep[toIdx[a]]);
		}
	}
	cin >> n;
	return 0;
}