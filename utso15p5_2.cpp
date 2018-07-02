#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include<iostream>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 50000
#define MAXM 100000
#define MAXB 17

int count_bits(int x) {
	return log2(x);
}

int sparseTable[MAXB][MAXN * 2];
void construct(const vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		sparseTable[0][i] = arr[i];
	int bs = 2, lvl = 1;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++)
			sparseTable[lvl][i] = min(sparseTable[lvl - 1][i], sparseTable[lvl - 1][i + (bs >> 1)]);
		bs <<= 1; lvl++;
	}
}

int queryTable(int l, int r) {
	int lvl = count_bits(r - l);
	return min(sparseTable[lvl][l], sparseTable[lvl][r - (1 << lvl)]);
}

vector<pii> adj[MAXN];

vector<int> tour;
int first[MAXN];
int sparsePar[MAXB][MAXN];
int sparseTree[MAXB][MAXN];
int h[MAXN];

void dfs(int i, int par = -1)
{
	first[i] = tour.size();
	tour.push_back(h[i]);
	sparsePar[0][i] = par;
	int lvl = 1, cur = par, jump = 2;
	while (jump <= h[i] && cur != -1) {
		sparsePar[lvl][i] = sparsePar[lvl - 1][cur];
		sparseTree[lvl][i] = max(sparseTree[lvl - 1][i], sparseTree[lvl - 1][cur]);
		cur = sparsePar[lvl][i];
		lvl++; jump <<= 1;
	}
	for (pii neigh : adj[i])
	{
		if (neigh.first == par)continue;
		h[neigh.first] = h[i] + 1;
		sparseTree[0][neigh.first] = neigh.second;
		dfs(neigh.first, i);
		tour.push_back(h[i]);
	}
}

int queryTree(int a, int b) {
	int res = -1;
	while (a != b) {
		int lcaH = queryTable(min(first[a], first[b]), max(first[a], first[b]) + 1);
		if (h[a] > h[b]) {
			int bs = h[a] - lcaH,
				lvl = count_bits(bs);
			res = max(res, sparseTree[lvl][a]);
			a = sparsePar[lvl][a];
		}
		else {
			int bs = h[b] - lcaH,
				lvl = count_bits(bs);
			res = max(res, sparseTree[lvl][b]);
			b = sparsePar[lvl][b];
		}
	}
	return res;
}

pair<int, pii> edj[MAXM];

int dj[MAXN];
int find(int x) {
	if (dj[x] == x)return x;
	return dj[x] = find(dj[x]);
}

bool inmst[MAXM];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		dj[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		edj[i] = { c, {a,b} };
	}
	sort(edj, edj + m);
	int mstc = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a = edj[i].second.first,
			b = edj[i].second.second,
			c = edj[i].first,
			pa = find(a),
			pb = find(b);
		if (pa == pb)continue;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		inmst[i] = true;
		dj[pa] = pb;
		mstc += c;
		cnt++;
	}
	if (cnt != n - 1)
	{
		printf("-1\n");
		return 0;
	}
	dfs(0);
	construct(tour);
	int mini = INT_MAX;
	for (int i = 0; i < m; i++) if (!inmst[i]) {
		int a = edj[i].second.first,
			b = edj[i].second.second,
			c = edj[i].first;
		int swp = queryTree(a, b);
		if (c <= swp)continue;
		mini = min(mini, mstc - swp + c);
	}
	if (mini == INT_MAX)mini = -1;
	printf("%d\n", mini);
	cin >> mini;
}