#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <functional>
#include <cstring>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 10000010

ll dp[MAXN];

ll f(ll n) {
	if (n == 2)return 1;
	if (n == 1)return 1;
	ll res;
	if (n < MAXN) {
		res = dp[n];
		if (res != -1)return res;
	}
	res = 0;
	int k = n;
	while (k >= 2) {
		int w = n / k, nxt = n / (w + 1);
		res += (k - nxt)*f(w);
		k = nxt;
	}
	if (n < MAXN) {
		return dp[n] = res;
	}
	else return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n; scanf("%d", &n);
	printf("%lld\n", f(n));
	cin >> n;
}