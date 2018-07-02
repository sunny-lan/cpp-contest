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

bool avail[10];

int main() {
	string s,y; cin >> s>>y;
	for (char c : y)
		avail[c - '0'] = true;
	int hd = (s[0] - '0') * 10 + (s[1] - '0'),
		md = (s[3] - '0') * 10 + (s[4] - '0') ,
		sd = (s[6] - '0') * 10 + (s[7] - '0');
	int ts = 3600 * hd + md * 60 + sd;
	int hb, mb, sb;
	int best = INT_MAX;
	for (int h = 0; h < 100; h++) {
		if (!avail[h % 10])continue;
		if (!avail[h / 10])continue;
		for (int m = 0; m < 100; m++) {
			if (!avail[m % 10])continue;
			if (!avail[m / 10])continue;
			for (int s = 0; s < 100; s++) {
				if (!avail[s % 10])continue;
				if (!avail[s / 10])continue;
				int altts= 3600 * h + m * 60 + s;
				if (abs(altts - ts) < best) {
					best = abs(altts - ts);
					hb = h, mb = m, sb = s;
				}
			}
		}
	}
	printf("%02d:%02d:%02d", hb, mb, sb);
}