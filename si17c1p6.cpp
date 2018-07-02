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

#define MAXN 100000

int m[MAXN];

int main() {
	int c, t; scan(c); scan(t);
	for (int i = 0; i < c; i++)
		scan(m[i]);
	sort(m, m + c);
	int lst = 0;
	int i = 0;
	for (; i < c; i++) {
		int inc = (m[i] - lst)*i;
		if (inc > t)break;
		t -= inc;
		lst = m[i];
	}

}