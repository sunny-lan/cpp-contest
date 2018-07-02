#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2005,m = 2,v = 27;

ll md[] = {200000033, 200000039};
bitset<200000040> d[m];
bitset<2001> dp[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n;
	cin >> s >> n;
	for(int i = 0; i < n; i++) {
		string w;
		cin >> w;
		ll hsh[m] = {0, 0};
		for(char c : w)
			for(int j = 0; j < m; j++)
				hsh[j] = (hsh[j] * v + (c - 'a' + 1)) % md[j];
		for(int j = 0; j < m; j++)
			d[j][hsh[j]] = 1;
	}
	int ans = 0;
	dp[s.length()][s.length()] = 1;
	for(int i = s.length() - 1; i >= 0; i--) {
		ll hsh[m] = {0, 0};
		for(int j = i; j < s.length(); j++) {
			for(int k = 0; k < m; k++)
				hsh[k] = (hsh[k] * v + (s[j] - 'a' + 1)) % md[k];
			for(int k = 0; k < m; k++)
				if(!d[k][hsh[k]])
					goto outer;
			dp[i] |= dp[j + 1];
		outer:
			continue;
		}
		ans += dp[i].count();
		dp[i][i] = 1;
	}
	printf("%d\n", ans);
}
