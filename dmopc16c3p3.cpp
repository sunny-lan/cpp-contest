#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 5000
#define MAXM 10000

int dp[2][MAXM + 1];

int s[MAXN];
int ma[MAXN];

int main() {
	memset(dp, -1, sizeof dp);

	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		scan(s[i]); scan(ma[i]);
	}

	dp[0][m] = 0;
	for (int i = 0; i < n; i++) {
		int cI = i % 2;
		int nI = (i + 1) % 2;
		memset(dp[nI], -1, sizeof dp[nI]);
		for (int j = 0; j <= MAXM; j++)if (dp[cI][j] != -1) {
			dp[nI][j] = max(dp[cI][j], dp[nI][j]);
			if (j >= s[i])
				dp[nI][j - s[i] + ma[i]] = max(dp[cI][j] + 1, dp[nI][j - s[i] + ma[i]]);
		}
	}

	int maxi = -1, idx = -1;
	for (int i = MAXM; i >= 0; i--)
		if (dp[n % 2][i] > maxi)
			maxi = dp[n % 2][i], idx = i;
	cout << maxi << " " << idx << endl;
	cin >> n;
}