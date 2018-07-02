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
	int x1, y1, x2, y2, xs, ys, d;
	scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &xs, &ys, &d);
	int dx1 = x1 - xs,
		dy1 = y1 - ys,
		dx2 = x2 - xs,
		dy2 = y2 - ys;
	if (dx1*dx1 + dy1*dy1 <= d*d) {
		printf("Yes\n");
		return 0;
	}
	if (dx2*dx2 + dy2*dy2 <= d*d) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
}