#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 3001
#define MAXM 101

long a[MAXN];
long b[MAXM];

static long dp[MAXN + 1][MAXM + 1][MAXM + 1][2];

int n, m;

long maxPies(int line, int i, int j, int prev) {
	long res = dp[line][i][j][prev];
	if (res != -1)
		return res;
	else
		res = 0;

	if (prev == 0) {
		if (line < n)
			res = max(res, maxPies(line + 1, i, j, 1) + a[line]);

		if (i <= j)
			res = max(res, maxPies(line, i, j - 1, 1) + b[j]);
	}

	if (line < n)
		res = max(res, maxPies(line + 1, i, j, 0));
	if (i <= j)
		res = max(res, maxPies(line, i + 1, j, 0));

	dp[line][i][j][prev] = res;
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int line = 0; line <= n; line++) {
		for (int i = 0; i <= m + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				dp[line][i][j][0] = -1;
				dp[line][i][j][1] = -1;
			}
		}
	}

	sort(b, b + m + 1);

	cout << maxPies(0, 1, m, 0) << endl;

	return 0;
}
