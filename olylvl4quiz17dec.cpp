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

#define MAXN 100

int x[MAXN];
int y[MAXN];

int main() {
	int n; scan(n);
	int minarea = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		for (int j = 0; j < i; j++) {
			int x1 = x[j], y1 = y[j];
			int slen = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
			minarea = min(minarea, slen*slen);
		}
	}
	printf("%d\n", minarea);
}