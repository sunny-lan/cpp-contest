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

#define MAXT 6
#define MAXN 1000
#define MAXC 3001

vector<pii> part[MAXT];

int dp[MAXT][MAXC];

int main() {
	memset(dp, -1, sizeof dp);

	int t, n, b; scan(t); scan(n);
	for (int i = 0; i < n; i++) {
		int c, v, t; scan(c); scan(v); scan(t);
		part[--t].push_back({ c,v });
	}

	memset(dp[0], 0, sizeof dp);

	scan(b);

	for (int i = 0; i < t; i++) {
		for (auto p : part[i]) {
			int c = p.first,
				v = p.second;
			for (int j = 0; j+c <= b; j++) {
				if (dp[i][j] == -1)continue;
				dp[i + 1][j + c] = max(dp[i][j] + v, dp[i + 1][j + c]);
			}
		}
	}

	int maxi = -1;
	for (int i = 0; i <= b; i++)
		maxi = max(maxi, dp[t][i]);
	cout << maxi << endl;
	cin >> maxi;
}