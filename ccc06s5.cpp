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

int n, m;

bool get(int v, int x, int y) {
	return (v >> (x + y*n)) & 1;
}

int set(int v, int x, int y, bool s) {
	if (s) return v | (1 << (x + y*n));
	else return v & ~(1 << (x + y*n));
}

int a, b, c;

int computeNext(int v) {
	int next = v;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (get(v, x, y)) {

			}
			else {

			}
		}
	}
}

#define MAXV 1100000

int deg[MAXV];

int main() {

}