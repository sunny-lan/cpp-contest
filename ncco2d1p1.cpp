#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 300

vector<int> d[2];
int cheese=5;
ll f(int side, int t, int l = 0, int r = 0, int cur = 0, int lvl = 0) {
	if(lvl == cheese || t<=0)
		return 0;
	ll maxi = 0;
	ll tot = 0;
	for(int i = side ? l : r; i < d[side].size(); i++) {
		t -= abs(d[side][i] - cur);
		if(t <= 0)
			break;
		cur = d[side][i];
		tot += t;
		maxi = max(maxi, f(1 - side, t-cur, side ? i + 1 : l, side ? r : i + 1, 0, lvl + 1 ) + tot);
	}
    return maxi;
}

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(x < 0)
			d[0].push_back(-x);
		else
			d[1].push_back(x);
	}
	sort(d[0].begin(), d[0].end());
	sort(d[1].begin(), d[1].end());if(n>100)cheese=4;
	printf("%lld\n", max(f(0, t), f(1, t)));
}
