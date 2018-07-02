#ifdef DMOJ

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 300000

vector<int> adj[MAXN];

int day[MAXN];

int dfs(int i) {
	int maxi = -1;
	for (int neigh : adj[i])
		maxi = max(maxi, dfs(neigh));
	if (maxi == -1)maxi = INT_MAX;
	return min(maxi, day[i]);
}

int main() {
	memset(day, 0x3f, sizeof day);
	int n, m, d; scan(n); scan(m); scan(d);
	for (int i = 0; i < m; i++) {
		int t, r; scan(t); scan(r);
		t--;
		//unordered_map<int, bool> cust;
		for (int j = 0; j < r; j++) {
			int d; scan(d);
			d--;
			adj[t].push_back(d);
		}
	}
	for (int i = 1; i <= d; i++) {
		int f; scan(f);
		f--;
		day[f] = min(day[f], i);
	}
	int res = dfs(0);
	if (res > d)
		printf("-1\n");
	else
		printf("%d\n", res);
	cin >> n;
}