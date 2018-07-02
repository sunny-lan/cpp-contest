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

int a[8];
int b[8];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++)
		scan(a[i]);
	for (int i = 0; i < m; i++)
		scan(b[i]);

	int at = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (b[j] < a[i])
				goto outer;
		at++;
	outer:continue;
	}
	int bt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (a[j] < b[i])
				goto outer1;
		bt++;
	outer1:continue;
	}
	printf("%d %d\n", at, bt);
	cin >> n;
}