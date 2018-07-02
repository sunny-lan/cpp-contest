#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 16
#define CUST (1<<MAXN)

int spd[MAXN];
int n;
int dp[CUST][2];

int f(int b, int s) {
	if (b == 0)return 0;
	int &res = dp[b][s];
	if (res != -1)return res;
	res = 1 << 30;
	if (s == 0) {
		for (int i = 0; i < n; i++)
			if ((b >> i) & 1)
				for (int j = i + 1; j < n; j++)
					if ((b >> j) & 1)
						res = min(res, f(b & (~(1 << i))& (~(1 << j)), 1) + max(spd[i], spd[j]));

	}
	else {
		for (int i = 0; i < n; i++) if ((~b >> i) & 1)
			res = min(res, f(b | (1 << i), 0) + spd[i]);
	}
	return  res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &spd[i]);
	//sort(spd, spd + n);
	printf("%d\n", f((1 << n) - 1, 0));
	cin >> n;
}