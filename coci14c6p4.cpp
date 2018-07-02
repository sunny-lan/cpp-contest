#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	int n, k; scan(n); scan(k);
	ll k2 = k;
	if (k2*k2 < n)
	{
		printf("-1\n");
		return 0;
	}
	int t = 0;
	for (int block = 0; block < (n + k - 1) / k; block++) {
		int bs = min(k, n - t);
		for (int i = 0; i < bs; i++, t++) {
			printf("%d ", bs+block*k - i);
		}
	}
	printf("\n");
	cin >> n;
}