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
typedef pair<bool, bool> pbb;

pbb dp[2][]

int main() {
	int t; scan(t);
	for (int i = 0; i < t; i++) {
		int f, sa = 0, sb = 0; scan(f);
		for (int j = 0; j < 8; j++) {
			int a; scan(a);
			sa += 1 << (3 * a);
		}
		for (int j = 0; j < 8; j++) {
			int b; scan(b);
			sb += 1 << (3 * b);
		}
	}
}