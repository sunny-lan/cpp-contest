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

int main() {
	int n; scanf("%d", &n);
	int cnt = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = a; b <= n; b++) {
			int c = a^b;
			if (c > n)continue;
			if (c < b)continue;
			if (c >= a + b)continue;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	cin >> cnt;
}