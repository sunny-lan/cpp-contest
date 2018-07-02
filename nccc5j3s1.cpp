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

#define MAXN 101

int a[MAXN];

int main() {
	int n, x; scanf("%d %d", &n, &x);
	int res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				int qust[] = { a[i], a[j], a[k] };
				sort(qust, qust + 3);
				if (qust[1] == x)
					res++;
			}
		}
	}
	printf("%d\n", res);
}