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

#define mod 1000000007

int main() {
	string s; cin >> s;
	int n = s.length();
	ll fwdHash = 0;
	ll bkHash = 0;
	ll pow = 1;
	int lastIdx = 0;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int ch = (s[i - 1] - 'a' + 1);
		fwdHash = (fwdHash + pow * ch) % mod;
		bkHash = (bkHash * 27 + ch) % mod;
		pow = pow * 27 % mod;
		if (fwdHash == bkHash) {
			for (int j = lastIdx; j < i; j++) {
				if (s[j] != s[i - j - 1])
					goto outer;
			}
			lastIdx = i;
			ll rolling = fwdHash;
			for (int j = 0; j + i < n; j++) {
				rolling = (rolling * 27 + (s[j + i] - 'a' + 1)) % mod;
				rolling = (rolling - (s[j] - 'a' + 1)*pow + mod) % mod;
				if (rolling == bkHash) {
					for (int k = 0; k < i; k++) {
						if (s[k] != s[j + k + 1])
							goto inner;
					}
					maxi = max(maxi, i);
				}
			inner:continue;
			}
		}
	outer: continue;
	}
	printf("%d\n", maxi);
	cin >> n;
}