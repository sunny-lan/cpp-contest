#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 64

ll dp[MAXN][2];
ll fib[MAXN];

int main() {
	fib[1] = 1, fib[2] = 1;
	dp[1][1] = 1, dp[1][0] = 0;
	dp[2][1] = 1, dp[2][0] = 0;
	for(int i = 3; i < MAXN; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		dp[i]=
	}

	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		ll n;
		scanf("%I64d", &n);
		ll res = 0;
		int fidx = MAXN - 1;
		while(n > 0) {
			while(fib[fidx] > n)
				fidx--;
			res += dp[fidx];
			n -= fib[fidx];
		}
		printf("%I64d\n", res);
	}
}
