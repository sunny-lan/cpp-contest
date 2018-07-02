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

int dig[10];
string a, b;

ll best = 0;
int res[20];
void f(int i, bool flg) {
	if (i == -1) {
		ll alt = 0;
		for (int i = a.length()-1; i >=0; i--) {
			alt *= 10;
			alt += res[i] ;
		}
		best = max(best, alt);
	}

	int kust;
	if (flg)
		kust = 9;
	else
		kust = b[i] - '0';

	if (flg) {
		for (int j = 9; j >= 0; j--)
			if (dig[j] > 0) {
				res[i] = j;
				dig[j]--;
				f(i - 1, true);
				dig[j]++;
				break;
			}
	}
	else {
		if (dig[kust] > 0) {
			res[i] = kust;
			dig[kust]--;
			f(i - 1, false);
			dig[kust]++;
		}

		for (int j = kust - 1; j >= 0; j--)
			if (dig[j] > 0) {
				res[i] = j;
				dig[j]--;
				f(i - 1, true);
				dig[j]++;
				break;
			}
	}
}

int main() {
	cin >> a >> b;
	reverse(b.begin(), b.end());
	bool flg = false;
	if (b.length() > a.length())
		flg = true;
	else
		b += "00000000000000000000";
	for (char c : a)
		dig[c - '0']++;
	f(a.length() - 1, flg);
	printf("%I64d\n", best);
	cin >> a;
}