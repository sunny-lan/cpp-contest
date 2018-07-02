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

#define MAXN 100
#define MAXK 5000010

int k[MAXN];
int c[MAXN];

bool dp[MAXK];
int num[MAXK];

int main() {

	int n, tot = 0; scan(n);
	for (int i = 0; i < n; i++)
	{
		scan(k[i]); scan(c[i]);
		tot += k[i] * c[i];
	}
	int K = tot / 2;
	int maxi = 0;
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		memset(num, 0, sizeof num);
		num[0] = 0;
		for (int j = c[i]; j <= K; j++)if (dp[j - c[i]] && num[j - c[i]] < k[i] && !dp[j]) {
			dp[j] = true;
			num[j] = num[j - c[i]] + 1;
			maxi = max(maxi, j);
		}
	}
	printf("%d\n", abs(tot - maxi * 2));
	cin >> n;
}