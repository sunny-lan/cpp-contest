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

#define MOD 1000000007
#define MAXN 210

vector<pair<int, char>> child[MAXN];

ll dp[MAXN][MAXN][2];
bool vis[MAXN][2];
int n, w, m;

void f(int i, int d) {
	if (vis[i][d])return;
	vis[i][d] = true;
	//if werewolf, but none left then impossible
	dp[i][0][d] = (d == 1 ? 0 : 1);
	//vice versa
	dp[i][1][d] = d;

	for (auto edge : child[i]) {
		f(edge.first, 1);
		f(edge.first, 0);

		for (int j = w; j >= d; j--) {
			ll cnt = 0;
			//num ways with ith subtree using j =
			//sum for all k
			//num ways with prev subtrees using k *
			//num ways with curr subtree using j-k
			for (int k = d; k <= j; k++) {
				if (edge.second == 'D' || d != 1)
					cnt += dp[edge.first][j - k][1] * dp[i][k][d] % MOD;
				if (edge.second == 'A' || d != 1)
					cnt += dp[edge.first][j - k][0] * dp[i][k][d] % MOD;
				cnt %= MOD;
			}
			dp[i][j][d] = cnt;
		}
	}
}

int deg[MAXN];

int main() {
	scan(n); scan(w); scan(m);
	for (int i = 0; i < m; i++) {
		char t; int a, b; scanf(" %c %d %d", &t, &a, &b);
		a--, b--;
		child[a].push_back({ b, t });
		deg[b]++;
	}

	//add supernode
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			child[n].push_back({ i, 'A' }); //shouldn't matter which type
	f(n, 0);
	printf("%d\n", dp[n][w][0]);
	cin >> n;
}