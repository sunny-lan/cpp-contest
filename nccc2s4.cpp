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

unordered_map<int, vector<int>> adj[MAXN];
bool good[MAXN];

int childbad[MAXN];
bool pfs(int i, int c, int k) {
	bool bad = adj[i][c].size() > 1;
	for (auto p : adj[i])
		for (int j : p.second)if (j != k) {
			if (pfs(j, p.first, i)) {
				if (childbad[i] != 0)
				{
					childbad[i] = -1;
					return true;
				}
				else {
					childbad[i] = j;
				}
			}
		}
	if (bad)return true;
	return childbad[i] != 0;
}

void dfs(int i, int c, int k) {
	if (childbad[i] == -1)return;

	for (auto p : adj[i]) {
		if (p.second.size() == 1)
			for (int j : p.second)if (j != k)
			{
				if (childbad[i] == 0) {
					dfs(j, p.first, i);
				}
				else {
					if (j == childbad[i])
						dfs(j, p.first, i);
				}
			}
	}
	if(childbad[i]==0)
	good[i] = true;
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		adj[a][c].push_back(b);
		adj[b][c].push_back(a);
	}
	pfs(1, -1, -1);
	dfs(1, -1, -1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (good[i])cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (good[i])
			printf("%d\n", i);
	cin >> n;
}