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

ll dp[31][31];
int fr[31], lb[31];
int m, n;

ll f(int r, int c) {
	if (r == m)return 1;
	ll &res = dp[r][c];
	if (res != -1)return res;
	res = 0;
	for (int i = lb[r]; i < min(fr[r], c); i++)
		res += f(r + 1, i + 1);
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		fr[i] = n;
		lb[i] = -1;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'R') {
				if (fr[i] == n) {
					fr[i] = j;
				}
			}
			else if (s[j] == 'B') {
				lb[i] = j;
			}
		}
	}

	printf("%lld", f(0, n));

	cin >> n;
}