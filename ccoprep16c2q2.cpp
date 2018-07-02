#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100001

int a[MAXN];
int dp[MAXN][2];
//dp[i][j] reps the best number from 0 to i-1 where j is whether i-1 is picked
int bitmask[MAXN][2];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int maxi = 0;

	for (int i = 0; i < n; i++) {
		//i-1 is not picked, and you don't pick i either
		if (dp[i][0] > dp[i + 1][0]) {
			maxi=max(maxi,dp[i + 1][0] = dp[i][0]);
			bitmask[i + 1][0] = bitmask[i][0];
		}
		//i-1 is picked, and you don't pick i
		if (dp[i][1] > dp[i + 1][0]) {
			maxi = max(maxi, dp[i + 1][0] = dp[i][1]);
			bitmask[i + 1][0] = bitmask[i][1];
		}
		//i-1 is not picked, and you pick i
		if (dp[i][0] + 1 > dp[i + 1][1]) {
			maxi = max(maxi, dp[i + 1][1] = dp[i][0] + 1);
			bitmask[i + 1][1] = a[i];
		}
		//i-1 is picked, and you pick i
		if ((bitmask[i][1] & a[i])!=0 && dp[i][1] + 1 > dp[i + 1][i]) {
			maxi = max(maxi, dp[i + 1][i] = dp[i][1] + 1);
			bitmask[i + 1][1] = a[i];
		}
	}

	cout << maxi << endl;
}