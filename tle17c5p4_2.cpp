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

#define MAXL 18

string s, t;
ll a;
ll psa[100001][MAXL];
ll dp[2][MAXL];

ll f(int dig, int lvl) {
	if (lvl == 0) {
		return 1;
	}

	if (dp[dig][lvl] != -1)return dp[dig][lvl];

	if (dig == 0) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0')
				psa[i][lvl] += f(0, lvl - 1);
			else
				psa[i][lvl] += f(1, lvl - 1);
		}
	}
	else {
		for (int i = 0; i < t.length(); i++) {
			if (t[i] == '0')
				psa[i][lvl] += f(0, lvl - 1);
			else
				cnt += f(1, lvl - 1);
		}
	}
	return dp[dig][lvl] = cnt;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		
	}
}