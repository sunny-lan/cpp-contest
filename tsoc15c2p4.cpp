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

#define MAXN 20000
#define INF 3000000

vector<int> adj[MAXN];
vector<int> bdj[MAXN];

int indeg[MAXN];
int outdeg[MAXN];

int dp[MAXN];
int cp[MAXN];

int paths(int i) {
	if (outdeg[i] == 0) return 1;

	int &res = dp[i];
	if (res != -1)return res;

	res = 0;
	for (int neigh : adj[i])
		res += paths(neigh);

	return res;
}

int dist(int i) {
	if (indeg[i] == 0)return 1;

	int &res = cp[i];
	if (res != -1)return res;

	res = INF;

	for (int neigh : bdj[i])
		res = min(res, dist(neigh) + 1);

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(cp, -1, sizeof cp);


	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		indeg[b]++, outdeg[a]++;
		adj[a].push_back(b);
		bdj[b].push_back(a);
	}

	int tot = 0;
	for (int i = 0; i < n; i++)if (indeg[i] == 0)
		tot += paths(i);

	printf("%d\n", tot);

	for (int i = 0; i < n; i++)if (outdeg[i] == 0)
		printf("%d ", dist(i));
	printf("\n");

	cin >> n;
}