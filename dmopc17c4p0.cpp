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

int main() {
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	int dx1 = x1 - x2,
		dx2 = x2 - x3,
		dx3 = x3 - x1;
	int dy1 = y1 - y2,
		dy2 = y2 - y3,
		dy3 = y3 - y1;
	printf("%d\n", min(dx1*dx1 + dy1*dy1, min(dx2*dx2 + dy2*dy2, dx3*dx3 + dy3*dy3)));
}