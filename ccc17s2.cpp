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

#define MAXN 100

int x[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &x[i]);
	sort(x, x + n);
	int mid = (n-1) / 2;
	int a = mid, b = mid + 1;
	while (a >= 0) {
		printf("%d ", x[a]);
		if (b < n)
			printf("%d ", x[b]);
		a--, b++;
	}
	cin >> n;
}