#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MOD 1000000007
#define MAXN 200000

vector<int> child[MAXN];

ll f(int i) {
	ll ways = 1;
	for (int j : child[i])
		ways *= f(j), ways %= MOD;
	ways *= child[i].size() + 1, ways %= MOD;
	for (int j = 1; j <= child[i].size(); j++)
		ways *= j, ways %= MOD;
	return ways;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int p; scanf("%d", &p);
		child[p].push_back(i);
	}

	printf("%lld\n", f(0));
	cin >> n;
}