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



struct Point {
	float x = 0, y = 0;

	Point() {
		x = 0, y = 0;
	}

	Point(float _x, float _y) {
		x = _x, y = _y;
	}
};

struct Vector {
	float x = 0, y = 0;

	Vector() {
		x = 0, y = 0;
	}

	Vector(float _x, float _y) {
		x = _x, y = _y;
	}
};

struct Track {
	Point P0;
	Vector v;
	Track() {
	}
};
// Assume that classes are already given for the objects:
//    Point and Vector with
//        coordinates {float x, y, z;}
//        operators for:
//            Point   = Point ± Vector
//            Vector =  Point - Point
//            Vector =  Vector ± Vector
//            Vector =  Scalar * Vector
//    Line and Segment with defining points {Point  P0, P1;}
//    Track with initial position and velocity vector
//            {Point P0;  Vector v;}
//===================================================================


Point operator+(Point const& a, Vector const& b) {
	return Point(a.x + b.x, a.y + b.y);
}

Vector operator -(Point const& a, Vector const& b) {
	return Vector(a.x - b.x, a.y - b.y);
}

Vector operator -(Point const& a, Point const& b) {
	return Vector(a.x - b.x, a.y - b.y);
}

Vector operator+(Vector const& a, Vector const& b) {
	return Vector(a.x + b.x, a.y + b.y);
}

Vector operator -(Vector const& a, Vector const& b) {
	return Vector(a.x - b.x, a.y - b.y);
}

Vector operator*(float const& a, Vector const& b) {
	return Vector(a * b.x, a * b.y);
}


#define SMALL_NUM   0.00000001 // anything that avoids division overflow
// dot product (3D) which allows vector operations in arguments
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y)
#define norm(v)    sqrt(dot(v,v))  // norm = length of  vector
#define d(u,v)     norm(u-v)        // distance = norm of difference
#define abs(x)     ((x) >= 0 ? (x) : -(x))   //  absolute value


// cpa_time(): compute the time of CPA for two tracks
//    Input:  two tracks Tr1 and Tr2
//    Return: the time at which the two tracks are closest
float
cpa_time(Track Tr1, Track Tr2)
{
	Vector   dv = Tr1.v - Tr2.v;

	float    dv2 = dot(dv, dv);
	if (dv2 < SMALL_NUM)      // the  tracks are almost parallel
		return 0.0;             // any time is ok.  Use time 0.

	Vector   w0 = Tr1.P0 - Tr2.P0;
	float    cpatime = -dot(w0, dv) / dv2;

	return cpatime;             // time of CPA
}
//===================================================================


// cpa_distance(): compute the distance at CPA for two tracks
//    Input:  two tracks Tr1 and Tr2
//    Return: the distance for which the two tracks are closest
float
cpa_distance(Track Tr1, Track Tr2)
{
	float    ctime = cpa_time(Tr1, Tr2);
	Point    P1 = Tr1.P0 + (ctime * Tr1.v);
	Point    P2 = Tr2.P0 + (ctime * Tr2.v);

	return d(P1, P2);            // distance at CPA
}
//===================================================================

Track toTrack(float ix1, float iy1, float ix2, float iy2, float iv) {
	Track t1;
	t1.P0 = Point(ix1, iy1);
	Point p1 = Point(ix2, iy2);
	t1.v = p1 - t1.P0;
	float tmp = norm(t1.v);
	t1.v.x /= tmp;
	t1.v.y /= tmp;
	t1.v = iv*t1.v;
	return t1;
}

int main() {
	int n, r; scan(n); scan(r);
	int ix1, iy1, ix2, iy2, iv;
	scanf("%d %d %d %d %d", &ix1, &iy1, &ix2, &iy2, &iv);
	Track t1 = toTrack(ix1, iy1, ix2, iy2, iv);
	for (int i = 1; i < n; i++) {
		int x1, y1, x2, y2, v;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
		Track t2 = toTrack(x1, y1, x2, y2, v);
		float dist = cpa_distance(t2, t1);
		//printf("dist:%fd\n", dist);
		if (dist <= r)
			printf("%d\n", i);
	}
	cin >> n;
}