#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 50001
#define MAXM 100001
#define MAXL 20


int n, m;
vector<pair<int, pii>> adj[MAXN];

int sparse2[MAXL][MAXN * 2];

int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

//finds lca
int query2(int i, int j) {
	if (i > j)return query2(j, i);
	int bsI = count_bits(j - i);
	return min(sparse2[bsI][i], sparse2[bsI][j - (1 << bsI)]);
}

void construct2(const vector<int> &val) {
	int bs = 1, bsI = 0, n = val.size();
	for (int i = 0; i < n; i++)sparse2[bsI][i] = val[i];
	bs <<= 1, bsI++;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++)
			sparse2[bsI][i] = min(sparse2[bsI - 1][i], sparse2[bsI - 1][i + (bs >> 1)]);
		bs <<= 1, bsI++;
	}
}


int sparsePar[MAXL][MAXN];
int sparse1[MAXL][MAXN];
int sparse3[MAXL][MAXN];
int h[MAXN];
vector<int> tour;
int first[MAXN];

void dfs(int i, int j) {
	sparsePar[0][i] = j;
	first[i] = tour.size(); tour.push_back(h[i]);
	for (auto neigh : adj[i]) {
		int k = neigh.first;
		if (k == j)continue;
		sparse1[0][k] = neigh.second.first;
		sparse3[0][k] = neigh.second.second;
		h[k] = h[i] + 1;
		dfs(k, i);
		tour.push_back(h[i]);
	}
}

void construct() {
	int bs = 2, lvl = 1;
	while (bs < n) {
		for (int i = 0; i < n; i++) {
			int par1 = sparsePar[lvl - 1][i],
				par2 = sparsePar[lvl][i] = sparsePar[lvl - 1][par1];
			sparse1[lvl][i] = max(sparse1[lvl - 1][i], sparse1[lvl - 1][par1]);
			sparse3[lvl][i] = max(sparse3[lvl - 1][i], sparse3[lvl - 1][par1]);
		}
		bs <<= 1, lvl++;
	}

	construct2(tour);
}

//finds max on path in tree
int query(int a, int b) {
	int maxi = 0, mini = INT_MAX;
	while (a != b) {
		int lca = query2(first[a], first[b] + 1);
		if (h[a] > h[b]) {
			int msb = count_bits(h[a] - lca);
			maxi = max(maxi, sparse1[msb][a]);
			mini = min(mini, sparse3[msb][a]);
			a = sparsePar[msb][a];
		}
		else {
			int msb = count_bits(h[b] - lca);
			maxi = max(maxi, sparse1[msb][b]);
			mini = min(mini, sparse3[msb][b]);
			b = sparsePar[msb][b];
		}
	}
	return maxi - mini;
}

int c[MAXN];

int main() {
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++) scan(c[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		pii w = { max(c[a],c[b]),  min(c[a],c[b]) };
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	dfs(0, -1);
	construct();

	for (int i = 0; i < q; i++) {
		int u, v; scan(u); scan(v);
		u--, v--;
		printf("%d\n", query(u, v));
	}

	cin >> n;
}