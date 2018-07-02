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

#define MAXN 100000

int a[MAXN];

int main() {
	int n; ll k, m; scan(n); scan(k); scan(m);
	bool sm = true;
	for (int i = 0; i < n; i++) {
		scan(a[i]);
		if (i > 0)sm &= a[i] == a[i - 1];
	}
	if (sm) {
		printf("%I64d\n", m*n%k);
	}
	else {
		int ft = 0;
		int lst = -1, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != lst) {
				ft += cnt%k;
				cnt = 0;
			}
			cnt++;
			lst = a[i];
		}
		ft += cnt%k;

		int rnd = 0;
		if (a[0] == a[n - 1]) {
			int begin = -1;
			lst = -1, cnt = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] != lst) {
					if (lst != -1) {
						if (begin == -1)
							begin = cnt;
						else
							rnd += cnt%k;
					}
					cnt = 0;
				}
				cnt++;
				lst = a[i];
			}
			rnd += (begin + cnt) % k;
		}
		else {
			rnd = ft;
		}

		printf("%I64d\n", (m - 1)*rnd + ft);
	}
	cin >> n;
}