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

//finds if two rectangles intersect
bool rectInter(vec2 a0, vec2 a1, vec2 b0, vec2 b1) {
	if (a0.x > a1.x)swap(a0.x, a1.x);
	if (a0.y > a1.y)swap(a0.y, a1.y);
	if (b0.x > b1.x)swap(b0.x, b1.x);
	if (b0.y > b1.y)swap(b0.y, b1.y);
	return a0.x < b1.x
		&& a1.x > b0.x
		&& a0.y < b1.y
		&& a1.y > b0.y;
}

//intersection between two line segments
//excludes endpoints of line segments
bool segmentInter(vec2 a0, vec2 a1, vec2 b0, vec2 b1) {
	if (!rectInter(a0, a1, b0, b1))return false;
	double crs0 = cross(a1 - a0, b0 - a0),
		crs1 = cross(a1 - a0, b1 - a0);
	return crs0*crs1 < 0;
}

//finds if point on line segment
bool pointInter(vec2 a0, vec2 a1, vec2 c) {
	if (abs(cross(a1 - a0, c - a0)) > DBL_EPSILON)return false;
	double dt = dot(a1 - a0, c - a0);
	if (dt < 0)return false;
	vec2 df = a1 - a0;
	double dst = df.x*df.x + df.y*df.y;
	return dt <= dst;
}

int main() {
	vec2 a0, a1, b0, b1;
	cin >> a0.x >> a0.y;
	cin >> a1.x >> a1.y;
	cin >> b0.x >> b0.y;
	cin >> b1.x >> b1.y;
	if (segmentInter(a0, a1, b0, b1))
		printf("ye");
	cin >> a0.x;
}