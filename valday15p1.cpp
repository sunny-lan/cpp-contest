#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXC 1000
#define MAXM 1000

int dp[MAXC+1][MAXM+1];

int n[MAXC];
int k[MAXC];

int main() {
	memset(dp, -1, sizeof dp);
	int c, m; scan(c); scan(m);
	for (int i = 0; i < c; i++) {
		scan(n[i]); scan(k[i]);
	}

	dp[0][0] = 0;
	for (int i = 0; i < c; i++)
		for (int j = 0; j <= m; j++)if (dp[i][j] != -1) {
			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
			if (k[i] + j <= m)
				dp[i + 1][j + k[i]] = max(dp[i][j] + n[i], dp[i + 1][j + k[i]]);
		}

	int maxi = 0;
	for (int i = 0; i <= m; i++)
		maxi = max(maxi, dp[c][i]);

	cout << maxi << endl;
}