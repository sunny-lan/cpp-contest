#include <cstring>
#include <iostream>
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
int r, c, s, b, k, m;
int temp[51][51];
int val[51][51];
int dp[55][55][55][55];
int f(int h, int pos, int t, int num) {
	int &res = dp[h][pos][t][num];
	if (res == -1) {
		if (h > r || num == k) res = 0;
		else {
			for (int i = MAX(0, pos - m); i <= MIN(pos + m, c - 1); i++) {
				res = MAX(res, f(h + 1, i, t, num));
				if ((temp[h][pos] != -1) && (t + temp[h][pos]) < b) {
					res = MAX(res, f(h + 1, i, t + temp[h][pos], num + 1) + val[h][pos]);
				}
			}
		}
	}
	return res;
}
int main()
{
	int x;//number of items
	int mini = 0;
	for (int i = 0; i < 1 << x; i++) {
		int cost = 0;
		int weight = 0;
		for (int j = 0; j < x; j++) {
			if ((i >> j) & 1) {
				cost += costof[j];
				weight += wieghtof[j];
			}
		}
		if (weight < maxWeight)
			mini = min(mini, cost);
	}


	memset(temp, -1, sizeof(temp));
	memset(dp, -1, sizeof(dp));
	int i;
	scanf("%d %d %d %d %d %d", &r, &c, &s, &b, &k, &m);
	for (i = 0; i < s; i++) {
		int t, v, y, x;
		scanf("%d %d %d %d", &t, &v, &x, &y);
		temp[y][--x] = t;
		val[y][x] = v;
	}
	printf("%d\n", f(0, 0, 0, 0));
	return 0;
}