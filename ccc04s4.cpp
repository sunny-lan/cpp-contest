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

#define PX 0
#define NX 1
#define PY 2
#define NY 3
#define PZ 4
#define NZ 5

int rot(int d, char c) {
	if (d == PX) {
		if (c == 'L')return PY;
		if (c == 'R')return NY;
		if (c == 'U')return PZ;
		if (c == 'D')return NZ;
	}
	if (d == NX) {
		if (c == 'L')return NY;
		if (c == 'R')return PY;
		if (c == 'U')return PZ;
		if (c == 'D')return NZ;
	}
	if (d == PY) {
		if (c == 'L')return NX;
		if (c == 'R')return PX;
		if (c == 'U')return PZ;
		if (c == 'D')return NZ;
	}
	if (d == NY) {
		if (c == 'L')return PX;
		if (c == 'R')return NX;
		if (c == 'U')return PZ;
		if (c == 'D')return NZ;
	}
	if (d == PZ) {
		if (c == 'L')return NX;
		if (c == 'R')return PX;
		if (c == 'U')return PZ;
		if (c == 'D')return NZ;
	}
}

int main() {

}