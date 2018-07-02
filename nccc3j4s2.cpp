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

int a[100];
int b[100];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scan(a[j]);
		}
		sort(a, a + n);
		b[i] = a[n / 2];
	}
	sort(b, b + n);
	printf("%d", b[n / 2]);
	cin >> n;
}