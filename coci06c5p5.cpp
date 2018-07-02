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

int n;
int v[MAXN];
unordered_map<int, int> dp[MAXN * 2];

int f(int i, int j) {
	int move = j - i;
	if (move > n)return 0;
	if (dp[j].find(i) != dp[j].end())
		return dp[j][i];
	int res;
	if (move % 2 == 1) res = max(
		f(i - 1, j) + v[(i + n) % n],
		f(i, j + 1) + v[j % n]
	);
	else res = min(
		f(i - 1, j),
		f(i, j + 1)
	);
	return dp[j][i] = res;
}

int main() {
	scan(n);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		scan(v[i]);
		v[i] %= 2;
		tot += v[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int res = f(i - 1, i + 1) + v[i];
		if (res > tot - res)
			cnt++;
	}
	printf("%d\n", cnt);
	cin >> n;
}