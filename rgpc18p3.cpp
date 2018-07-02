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

#define MAXN 1000010

int psa[MAXN];

int main() {
	int n, t; scanf("%d %d", &n, &t);

	for (int i = 0; i < t; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a--;
		psa[a] += c;
		psa[b] -= c;
	}

	for (int i = 0; i < n; i++)
		psa[i + 1] += psa[i];

	int l; scanf("%d", &l);
	int tot = 0;
	int maxi = 0;
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		tot += psa[i];
		while (tot > l)
			tot -= psa[ptr], ptr++;
		maxi = max(maxi, i - ptr + 1);
	}

	printf("%d\n", maxi);

	cin >> n;
}