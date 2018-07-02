#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int besthub(int n, int L, int x[], ll b) {
	int r = 0, m = 0, res = 0;
	ll lsm = 0, rsm = 0;
	for(int l = 0; l < n; lsm -= x[l], l++)
		while(r < n) {
			int trg = (l + r) / 2;
			for(; m < trg; m++)
				lsm += x[m], rsm -= x[m];
			rsm += x[r], r++;
			ll alt = ((ll)(m - l) * x[m] - lsm) + (rsm - (ll)(r - m) * x[m]);
			if(alt > b)
				break;
			res = max(res, r - l);
		}
	return res;
}

int xx[] = {1, 2, 10, 12, 14};

int main() {
	printf("%d\n", besthub(5, 20, xx, 6));
}
