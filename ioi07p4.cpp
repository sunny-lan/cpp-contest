#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n;
int v[MAXN];
int dp[2][4][4][4][4];

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		if(s[i] == 'M')
			v[i] = 1;
		else if(s[i] == 'F')
			v[i] = 2;
	dp[0][3][3][3][3] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int cl = i % 2, nl = (i + 1) % 2;
		memset(dp[nl], -1, sizeof dp[nl]);
		for(int a1 = 0; a1 < 4; a1++)
			for(int a2 = 0; a2 < 4; a2++)
				for(int b1 = 0; b1 < 4; b1++)
					for(int b2 = 0; b2 < 4; b2++) {
						int cur = dp[cl][a1][a2][b1][b2];
						if(cur != -1)
						{
							int a[4] = {0}, b[4] = {0};
							a[v[i]] = a[a1] = a[a2] = 1;
							b[v[i]] = b[b1] = b[b2] = 1;
							int ac = 0, bc = 0;
							for(int j = 0; j < 3; j++)
								ac += a[j], bc += b[j];
							ans = max(max(
                               dp[nl][v[i]][a1][b1][b2] = max(cur + ac, dp[nl][v[i]][a1][b1][b2]),
                               dp[nl][a1][a2][v[i]][b1] = max(cur + bc, dp[nl][a1][a2][v[i]][b1])
                            ), ans);
						}
					}
	}
	printf("%d\n", ans);
}
