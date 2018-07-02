#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1001

int v[MAXN];

int main() {
	int res = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		for (int j = 0; j < i; j++)
			if (v[j] < v[i])
				res++;
	}
	printf("%d\n", res);
}