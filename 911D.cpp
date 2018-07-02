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

#define MAXN 1500

int a[MAXN];

int main() {
	int n; scan(n);
	bool e = 0;
	for (int i = 0; i < n; i++) {
		scan(a[i]);
		for (int j = 0; j < i; j++)
			if (a[j] > a[i])
				e = !e;
	}
	int m; scan(m);
	for (int i = 0; i < m; i++) {
		int l, r; scan(l); scan(r);
		int sz = r - l+1;
		int cnt = sz*(sz - 1) / 2;
		if (cnt % 2 == 1)
			e = !e;
		if (e)printf("odd\n");
		else printf("even\n");
	}
	cin >> n;
}