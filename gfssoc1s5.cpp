#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int val[55][55];
int temp[55][55];

int dp[55][55][55][55];

int m, rows, cols, k, b;

int f(int t, int s, int r, int c) {
	if (s == k || r > rows || t >= b)
		return 0;

	int res = dp[t][s][r][c];
	if (res != -1)
		return res;

	res = 0;

	for (int i = max(0, c - m); i <= min(cols - 1, c + m); i++) {
		res = max(res, f(t, s, r + 1, i));
		if (val[r][c] != -1 && temp[r][c] + t < b)
			res = max(res, f(t + temp[r][c], s + 1, r + 1, i) + val[r][c]);
	}

	dp[t][s][r][c] = res;
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(val, -1, sizeof val);
	int s;
	cin >> rows >> cols >> s >> b >> k >> m;
	for (int i = 0; i < s; i++) {
		int t1, v1, c, r;
		cin >> t1 >> v1 >> c >> r;
		c--;
		val[r][c] = v1, temp[r][c] = t1;
	}
	cout << f(0, 0, 0, 0) << endl;
	cin >> s;
}