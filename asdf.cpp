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

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 85

int n, t;
pii r[MAXN];
unordered_map<int, int> v[MAXN];

int hsh(vector<int> id) {
	int bs = 1, hs = 0;
	for (int i : id) {
		hs += i * bs;
		bs *= n;
	}
	hs += id.size() * bs;
	cout << "hash ";
	for (int i : id)
		cout << i << " ";
	cout << "= " << hs << endl;
	return hs;
}

int bst[MAXN];

int dfs(int i, vector<int> cur) {
	if (i == n)
		return cur.size();

	int h = hsh(cur);
	if (v[i].count(h) > 0)
		return v[i][h];

	int mini = INT_MAX;
	for (int kk = 0; kk < cur.size(); kk++) {
		int k = cur[kk];
		if (abs(r[k].s - r[i].s) <= abs(r[k].f - r[i].f)) {
			vector<int> nxt = cur;
			nxt[kk] = i;
			int alt = dfs(i + 1, nxt);
			if (alt<mini) {
				mini = alt;
				bst[i] = kk;
			}
		}
	}
	if (mini == INT_MAX)
	{
		bst[i] = cur.size();
		vector<int> nxt = cur;
		nxt.push_back(i);
		mini = dfs(i + 1, nxt);
	}
	cout << "mini " << i << ", ";
	for (int i : cur)
		cout << i << " ";
	cout << "= " << mini << endl;
	return v[i][h] = mini;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &r[i].s, &r[i].f);
	sort(r, r + n);
	printf("%d\n", dfs(0, {}));
	for (int i = 0; i<n; i++)
		printf("%d\n", bst[i] + 1);
}

