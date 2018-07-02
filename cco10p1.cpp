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

#define MAXN 1010

vector<int> children[MAXN];

int w[MAXN];
int dp[MAXN][MAXN];

int main() {
	int d; scan(d);
	for (int i = 0; i < d; i++)
		scan(w[i]);

	int f; scan(f);
	for (int c = 0; c < f; c++) {
		int i, j; scan(i); scan(j);
		i--, j--;
		children[i].push_back(j);
	}

	memset(dp, -1, sizeof dp);

	dp[0][0] = 0;

	int t; scan(t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < d; j++) if (dp[i][j] == 0) {
			for (int child : children[j])
				if (dp[i][child] == -1)
					dp[i][child] = w[child];
		}
		for (int j = 0; j < d; j++) if (dp[i][j] != -1)
			dp[i + 1][j] = dp[i][j] - 1;
	}

	for (int i = 0; i < d; i++) {
		int cnt = 0;
		for (int j = 0; j <= t; j++)
			if (dp[j][i] == 0)cnt++;
		printf("%d\n", cnt);
	}

	cin >> d;

}