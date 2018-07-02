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
	int t=0;
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int f; scan(f);
		if (f == 1)continue;
		if (f == 2) {
			t++;
			continue;
		}
		for (int j = 2; j*j <= f; j++) {
			if (f%j == 0)goto outer;
		}
		t++;
	outer:continue;
	}
	printf("%d\n", t);
	cin >> t;
}