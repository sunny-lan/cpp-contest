#include <iostream>
#include <algorithm>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 51

int dp[MAXN][MAXN][MAXN + 1][MAXN + 1];
int raisins[MAXN][MAXN];

#define value raisins
int n, m;

int prefix[MAXN + 1][MAXN + 1];

inline int sum(int x, int y, int x2, int y2) {
	int whole = prefix[y2][x2];
	int lcol = prefix[y][x2];
	int minsqr = prefix[y][x];
	int ucol = prefix[y2][x];
	return whole - ((lcol + ucol) - minsqr);
}

void construct() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			prefix[i][j] = prefix[i - 1][j] + value[i - 1][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			prefix[i][j] += prefix[i][j - 1];
}

int f(int i, int j, int k, int l) {
	if (i >= k || j >= l) return 0;
	if (k - i == 1 && l - j == 1) return 0;

	int res = dp[i][j][k][l];
	if (res != -1)
		return res;

	res = INT_MAX;

	for (int m = i + 1; m < k; m++) {
		int alt1 = f(i, j, m, l), alt2 = f(m, j, k, l);
		if (alt1 == INT_MAX || alt2 == INT_MAX) continue;
		res = min(res, alt1 + alt2 + sum(j, i, l, k));
	}

	for (int m = j + 1; m < l; m++) {
		int alt1 = f(i, j, k, m), alt2 = f(i, m, k, l);
		if (alt1 == INT_MAX || alt2 == INT_MAX) continue;
		res = min(res, alt1 + alt2 + sum(j, i, l , k));
	}

	dp[i][j][k][l] = res;

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scan(raisins[i][j]);

	construct();

	cout << f(0, 0, n, m) << endl;
}