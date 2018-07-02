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

#define MAXN 51
#define MAXS 1001

int h[MAXN];
int e[MAXN];
int p[MAXN];

pii dp[MAXN][MAXS];

int main() {
	memset(dp, -1, sizeof dp);
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(h[i]); scan(e[i]); scan(p[i]);
	}
	dp[0][0] = { 0,0 };
	int s; scan(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) if (dp[i][j].first != -1) {
			dp[i + 1][j] = dp[i][j] > dp[i + 1][j] ? dp[i][j] : dp[i + 1][j];

			int hp = h[i];
			int th = dp[i][j].first + h[i];
			for (int sc = 1; hp > 0 && sc*p[i] + j <= s; sc++) {
				pii alt = { th, dp[i][j].second - sc };
				dp[i + 1][sc*p[i] + j] = alt > dp[i + 1][sc*p[i] + j] ? alt : dp[i + 1][sc*p[i] + j];
				hp -= e[i];
				th += hp;
			}
		}
	}
	pii ans = { -1,1 };
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= s; j++)
			ans = dp[i][j] > ans ? dp[i][j] : ans;
	printf("%d\n%d\n", ans.first, -ans.second);
	cin >> n;
}