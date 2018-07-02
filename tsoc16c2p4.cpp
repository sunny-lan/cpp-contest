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

#define MAXN 10010

bool dp[MAXN][MAXN];
bool of[MAXN];

vector<int> ps;

int main() {
	for (int i = 2; i <= MAXN; i++)
	{
		for (int j = 2; j*j <= i; j++)
			if (i%j == 0)goto nxt;
		ps.push_back(i);
	nxt:continue;
	}

	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int k; scan(k);
		for (int p : ps)
			if (p*k > n)break;
			else
				of[p*k] = true;
	}
	dp[0][0] = true;
	for (int i = 0; i <= n; i++) if (dp[i][i])
		for (int j = 0; i + j <= n; j++)
			dp[i+1][j + i] |= of[j];

	for (int p : ps)
		if (p > n)break;
		else {
			if (dp[n][p]) {
				printf("its primetime\n");
				return 0;
			}
		}

		printf("not primetime\n");
		cin >> n;
}