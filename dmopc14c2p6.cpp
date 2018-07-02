#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MAXBS 333

typedef long long ll;

ll m[MAXN];
vector<ll> sorted[MAXBS];
ll suffix[MAXBS][MAXBS];

int main() {
	int n;
	scanf("%d", &n);
	int bs = sqrt(n);
	int bcount = 0;
	int i = 0;
	while (i < n) {
		for (int j = 0; j < bs; j++) {
			scanf("%lld", &m[i]);
			sorted[bcount].push_back(m[i]);
			if (++i >= n)
				break;
		}
		sort(sorted[bcount].begin(), sorted[bcount].end());
		for (int i = sorted[bcount].size()-1; i >= 0; i--)
			suffix[bcount][i] = suffix[bcount][i + 1] + sorted[bcount][i];
		bcount++;
	}
	int x;
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		int a, b;
		ll q;
		scanf("%d %d %lld", &a, &b, &q);
		int startb = a / bs;
		int endb = b / bs;
		ll res = 0;
		for (int j = a; j < startb; j++)
			if (m[j] >= q)
				res += m[j];
		for (int j = startb; j < endb; j++)
			res += suffix[j][lower_bound(sorted[j].begin(), sorted[j].end(), q) - sorted[j].begin()];
		for (int j = endb*bs; j <= b; j++)
			if (m[j] >= q)
				res += m[j];
		cout << res << endl;
	}
	cin >> n;
}