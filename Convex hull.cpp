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

struct vec2 {
	double x, y;

	vec2(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

vec2 operator -(vec2 a, vec2 b) {
	return vec2(a.x - b.x, a.y - b.y);
}

double cross(vec2 a, vec2 b) {
	return a.x*b.y - b.x*a.y;
}

double dot(vec2 a, vec2 b) {
	return a.x*b.x + a.y*b.y;
}

#define MAXN 100000

vec2 pts[MAXN];

int main() {
	int n; scan(n);
	vec2 pivot;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &pts[i].x, &pts[i].y);

	}
}