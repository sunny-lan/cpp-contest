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

#define MAXN 200000

int a[MAXN];
bool rem[MAXN];

int main() {
	int n, m, k; scan(n); scan(m); scan(k);
	for (int i = 0; i < n; i++)
		scan(a[i]);
	sort(a, a + n);
	int cnt = 0, st = 0, res = 0;
	for (int ed = 0; ed < n; ed++) {
		cnt++;
		while (a[st] <= a[ed] - m) {
			if (!rem[st])cnt--;
			st++;
		}
		for (int j = ed; cnt >= k; j--) {
			rem[j] = true;
			cnt--;
			res++;
		}
	}
	printf("%d", res);
	cin >> n;
}