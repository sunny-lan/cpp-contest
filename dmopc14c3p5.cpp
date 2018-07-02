#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

using namespace std;

typedef unsigned long ull;

#define MAXN 20
#define MAXM 50

int n, m;

string line;

ull bm[MAXM];
ull obm;
ull fbm;

ull INF;

unordered_map<ull, pair<ull, ull>> dp[MAXM][2];

pair<ull, ull> f(int i, ull b, int p) {
	//base cases
	if (p == 1 && b == fbm) {
		return make_pair(0UL, 0UL);
	}
	if (i == m) {
		return make_pair(INF, 0UL);
	}

	if (dp[i][p].find(b) != dp[i][p].end())
		return dp[i][p][b];

	ull res = INF;
	ull r2 = 0UL;

	//pick case
	pair<ull, ull> alt = f(i + 1, b | bm[i], 1);
	if (alt.first != INF && alt.first + 1 < res) {
		res = alt.first + 1;
		r2 = alt.second | (1UL << i);
	}

	//drop case
	alt = f(i + 1, b, p);
	if (alt.first != INF && alt.first < res) {
		res = alt.first;
		r2 = alt.second;
	}

	pair<ull, ull> thing = make_pair(res, r2);

	dp[i][p][b] = thing;
	return thing;
}

int main() {
	cin >> n >> m;
	ws(cin);
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		for (int j = 0; j < m; j++)
			if (line[j] == 'X')
				bm[j] |= 1 << i;
	}
	obm = fbm = (1UL << n) - 1UL;
	INF = (ull)(n * 2);
	for (int i = 0; i < m; i++)
		obm &= ~bm[i];
	pair<ull, ull> res = f(0, obm, 0);
	cout << res.first << endl;
	ull r2 = res.second;
	for (int i = 1; i <= m; i++) {
		if (r2 & 1)
			cout << i << " ";
		r2 >>= 1;
	}
	cout << endl;
	cin >> n;
}