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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int midx = 0;
	for (char c : s) {
		if (midx == 0 && c == 'o')
			midx++;
		if (midx == 1 && c == 'u')
			midx++;
		if (midx == 2 && c == 'r')
			midx++;
	}
	if (midx == 3)
		printf("Y\n");
	else
		printf("N\n");
}