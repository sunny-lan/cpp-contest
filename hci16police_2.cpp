#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100001

ll pos[MAXN];

ll dp[MAXN];

int main() {
	memset(dp, 0x3f, sizeof dp);
	int n; ll h; scan(n); scan(h);
	for (int i = 1; i <= n; i++) {
		scan(pos[i]);
	}

	dp[0] = 0ull;
	int j = 0;
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		for (; j < i; ++j) {
			ll tmp = dp[j] + h + (pos[i] - pos[j + 1])*(pos[i] - pos[j + 1]);
			if (tmp <= dp[i]) {
				t = j;
				dp[i] = tmp;
			}
		}
		j = t;
	}

	cout << dp[n] << endl;
	cin >> n;
}