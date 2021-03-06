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

bool perfect[1000010];

int main() {
	for (int i = 0; i*i <= 1000000; i++) {
		perfect[i*i] = true;
	}
	int n; scan(n);
	int maxi = -INT_MAX;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (!perfect[a])
			maxi = max(a, maxi);
	}
	printf("%d", maxi);
}