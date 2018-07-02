#ifdef DMOJ

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int main() {
	int x0, y0, n; scanf("%d %d %d", &x0, &y0, &n);
	int maxi = 0;

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		maxi = max(maxi, abs(x0 - x)+ abs(y0 - y));
	}

	printf("%d", maxi*maxi * 2);
	cin >> maxi;
}