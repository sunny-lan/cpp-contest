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


int main() {
	int t; scan(t);
	for (int test = 0; test < t; test++) {
		ll x; scan(x);
		int cnt = 0;
		int chlen = 0;
		int h = 0;
		bool f = false;
		bool first = true;
		for (int i = 63; i >= 0; i--) {
			if ((x >> i) & 1) {
				chlen++;
				if (f)
					cnt += h;
				h = 0;
				f = true;
			}
			else {
				h++;
				if (chlen != 0) {
					int alt1 = chlen + 2;
					int alt2 = chlen * 2;
					if (first)alt2--;
					alt2 = max(0, alt2);
					cnt += min(alt1, alt2);
					first = false;
				}
				chlen = 0; 
			}
		}
		if (chlen != 0) {
			int alt1 = chlen + 2;
			int alt2 = chlen * 2;
			if (first)alt2--;
			alt2 = max(0, alt2);
			cnt += min(alt1, alt2);
		}
		cnt += h;
		printf("%d\n", cnt);
	}
}