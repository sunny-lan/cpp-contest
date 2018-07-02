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

#define MAXN 30010
int a[2][MAXN];

int main() {
	int n; scan(n);
	if (n == 2) {
		printf("1\n1 1");
	}
	else {
		if (n % 2 == 0) {
			printf("0");
			printf("\n%d", n / 2);
			int t = 0;
			for (int i = 1; t < n / 2; i++)
				printf(" %d %d", i, n - i + 1), t += 2;
		}
		else {
			int subsize = n / 2;
			ll x = 0, y = 0;
			for (int i = 0; i < subsize; i++) {
				if (i % 2 == 0) {
					x += a[0][i] = n-(i  * 2) ;
					y += a[1][i] =  n-(i  * 2 + 1);
				}
				else {
					y += a[1][i] = n-(i  * 2) ;
					x += a[0][i] = n-( i  * 2  + 1);
				}
			}
			int remain = n - subsize * 2;
			int cnt = subsize;
			if (remain == 1)
				if (x < y)
					x++, a[0][subsize] = 1, cnt++;
				else
					y++, a[1][subsize] = 1;
			printf("%I64d\n%d", abs(x - y), cnt);
			for (int i = 0; i < cnt; i++)
				printf(" %d", a[0][i]);
		}
	}
	cin >> n;
}