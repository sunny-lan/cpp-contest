#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXY 1000000

int bit[MAXY];

void update(int p, int v) {
	for(int i = p; i < MAXY; i += i & -i)
		bit[i] += v;
}

int query(int p) {
	int res = 0;
	for(int i = p; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}

#define MAXB 61

ll rv(ll y) {
	ll res = 0;
	for(int i = 0; i <= MAXB; i++)
		res |= ((y >> (MAXB - i)) & 1) << i;
	return res;
}

#define MAXN 200000

int ans[MAXN];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector<pair<ll, pair<pll, int>>> evts;
	vector<ll> car;
	for(int i = 0; i < n; i++) {
		ll x, y;
		int v;
		scanf("%lld %lld %d", &x, &y, &v);
		x = rv(x), y = rv(y);
		ll lx = x - (x & -x),
		   hx = x + (x & -x) - 1;
		ll ly = y - (y & -y),
		   hy = y + (y & -y) - 1;
		car.push_back(ly);
		car.push_back(hy);
		evts.push_back({lx, {{ly, hy}, v}});
		evts.push_back({hx, {{ly, hy}, -v}});
	}

	vector<pair<pll, int>> points;
	for(int i = 0; i < q; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		points.push_back({{x, y}, i});
		car.push_back(y);
	}

	sort(evts.begin(), evts.end());
	sort(car.begin(), car.end());
	sort(points.begin(), points.end());
	car.resize(unique(car.begin(), car.end()) - car.begin());
	unordered_map<ll, int> ord;
	for(int i = 0; i < car.size(); i++)
		ord[car[i]] = i;

	int j = 0;
	for(int i = 0; i < evts.size();) {
		ll cx = evts[i].first;
		while(i < evts.size() && evts[i].first == cx)
			update(evts[i].second.first.first, evts[i].second.second),
				   update(evts[i].second.first.second, -evts[i].second.second),
				   i++;
		while(j < q && points[j].first.first == cx)
			ans[points[j].second] = query(points[j].first.second),
									j++;
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}
