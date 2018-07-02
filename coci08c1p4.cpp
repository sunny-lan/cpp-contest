#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[32][2];
int mask, lim;
int cnt(int idx = 31, int cry = 0) {
	if(idx == -1)
		return 1;
	int &res = dp[idx][cry];
	if(res != -1)
		return res;
	int md = (mask >> idx) & 1,
		ld = (lim >> idx) & 1;
	if(md)
		res = cnt(idx - 1, cry || ld);
	else {
		if(cry)
			res = 2 * cnt(idx - 1, 1);
		else {
			if(ld)
				res = cnt(idx - 1, cry) + cnt(idx - 1, 1);
			else
				res = cnt(idx - 1, cry);
		}
	}
	return res;
}

int calc(int c, int r) {
//	cout << "(" << c << "," << r << ")" << endl;
	memset(dp, -1, sizeof dp);
	mask = c;
	lim = r;
	return cnt();
}

int main() {
	int r, c;
	ll k;
	scanf("%d %d %lld", &r, &c, &k);
	int diag = 1, lec, ler;
	while(true) {
		int ec = min(diag, c), er = max(0, diag - c);
		int fl = min(r - er, ec);
		ec--;
//		cout << "diag=" << diag << " fl=" << fl << " k=" << k <<" ec="<<ec<<" er="<<er<< endl;
		if(k <= fl) {
			ll tot = 0;

			if(diag % 2) {
				int i = 0;
				for(; k > 0; i++)
				{
					int diff = ec - i, nr = er + diff, nc = ec - diff;
					if(nr >= 0 )
						tot += calc(nc, min(r - 1, nr)), k -= nr < r ? 1 : 0;
				}
				for(; i < c; i++) {
					int diff = lec - i, nr = ler + diff, nc = lec - diff;
					if(nr >= 0)
						tot += calc(nc, min(r - 1, nr));
				}
			} else {
			    int i=c-1;
				for(;k>0; i--)
				{
					int diff = ec - i, nr = er + diff, nc = ec - diff;
					if(nr >= 0)
						tot += calc(nc, min(r - 1, nr)), k--;
				}
				for(; i>=0; i--) {
					int diff = lec - i, nr = ler + diff, nc = lec - diff;
					if(nr >= 0)
						tot += calc(nc, min(r - 1, nr));
				}
			}
			printf("%lld", tot);
			return 0;
		}
		k -= fl;
		diag++;
		lec = ec, ler = er;
	}
}
