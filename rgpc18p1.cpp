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
	int n, m; scanf("%d %d", &n,
		&m);

	if (n%m==0) {
		printf("yes %d\n", n / m);
	}
	else {
		for (int i = m;; i++)
			if (n%i == 0) { printf("no %d\n", i - m); 
		break;
		}
	}
}