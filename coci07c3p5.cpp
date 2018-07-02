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

string a, b;
ll dp[17][136][2][2];
int sw[17];
int ans[17];
bool flag = false;

ll f(int d, int s, bool fl, bool fh) {
	if (d < 0) {
		if (s == 0) {
			if (!flag)memcpy(ans, sw, sizeof ans);
			flag = true;
			return 1;
		}
		else return 0;
	}
	if (s < 0)return 0;
	ll res = dp[d][s][fl][fh];
	if (res != -1)
		return res;
	res = 0;
	int st = fl ? a[d] - '0' : 0, ed = fh ? b[d] - '0' : 9;
	for (int i = st; i <= ed; i++) {
		sw[d] = i;
		res += f(d - 1, s - i, fl && (st == i), fh && (ed == i));
	}
	return dp[d][s][fl][fh] = res;
}

int main() {
	memset(dp, -1, sizeof dp);
	int s;
	cin >> a >> b >> s;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.length() <= 16) a += '0';
	while (b.length() <= 16) b += '0';
	printf("%lld\n", (ll)f(16, s, 1, 1));
	flag = false;
	for (int i = 16; i >= 0; i--) {
		if (ans[i] != 0)
			flag = true;
		if (flag)
			printf("%d", ans[i]);
	}
	printf("\n");
	cin >> s;
}