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

ll a[50];

int main() {
	int n; scan(n);
	if (n == 1) { printf("0"); return 0; }
	for (int i = 0; i < n; i++)
		scan(a[i]);
	ll tot = 0;
	while (true) {
		sort(a, a + n);
		if (a[n - 2] == 0)break;
		a[n - 1]--;
		a[n - 2]--;
		tot++;
	}
	printf("%lld", tot);
	cin >> n;
}