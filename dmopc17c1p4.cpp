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

#define MAXN 5010

ll dp[2][MAXN][2];
int g[MAXN];
int h[MAXN];
int q[MAXN];
int t[MAXN];

int main() {
	memset(dp, -1, sizeof dp);

	int N, H; scan(N); scan(H);
	for (int i = 0; i < N; i++) {
		scan(g[i]); scan(h[i]); scan(q[i]); scan(t[i]);
	}

	dp[0][0][0] = 0;

	for (int i = 0; i < N; i++) {
		int cd = i % 2;
		int nd = (i + 1) % 2;
		memset(dp[nd], -1, sizeof dp[nd]);
		for (int j = 0; j <= H; j++) {
			if (dp[cd][j][0] != -1) {
				//considering curr npc for travel
				ll curr = dp[cd][j][0];

				//skip npc
				dp[nd][j][0] = max(curr, dp[nd][j][0]);

				//travel to npc
				if (j + h[i] <= H)
					dp[cd][j + h[i]][1] = max(curr + g[i], dp[cd][j + h[i]][1]);
			}

			if (dp[cd][j][1] != -1) {
				//already travelled to curr npc
				ll curr = dp[cd][j][1];

				//move on to next
				dp[nd][j][0] = max(curr, dp[nd][j][0]);

				//keep on doing curr
				if (j + t[i] <= H)
					dp[cd][j + t[i]][1] = max(curr + q[i], dp[cd][j + t[i]][1]);
			}
		}
	}

	ll maxi = 0;
	for (int j = 0; j <= H; j++)
		for (int k = 0; k < 2; k++)
			maxi = max(dp[N % 2][j][k], maxi);

	cout << maxi << endl;
	cin >> maxi;
}