#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 100000

int xrd[MAXN];
int p[MAXN];
pii find(int x) {
	if(p[x] == x)
		return {p[x], 0};
	pii res = find(p[x]);
	res.second ^= xrd[x];
	return res;
}

unordered_map<int, ll> cnt[MAXN];
int r[MAXN];
ll tot = 0;
void merge(int x, int y, int xr) {
	pii px = find(x),
		py = find(y);
	if(r[px.first] > r[py.first])
		swap(px, py);
	for(auto v : cnt[px.first])
		tot += v.second * cnt[py.first][v.first ^ px.second ^ py.second ^ xr];
	for(auto v : cnt[px.first])
		cnt[py.first][v.first ^ px.second ^ py.second ^ xr] += v.second;
//	cout << py.first<<": "<<endl;
//	for(pii v:cnt[py.first])
//        cout << " "<<v.first<<": "<<v.second<<endl;
	r[py.first] += r[px.first];
	r[px.first] = 0;
	p[px.first] = py.first;
	xrd[px.first] = py.second ^ xr ^ px.second;
}

ll ans[MAXN];
int a[MAXN], b[MAXN], z[MAXN];
int q[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cnt[i][0] = 1;
		r[i] = 1;
		p[i] = i;
	}
	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a[i], &b[i], &z[i]);
		a[i]--, b[i]--;
	}

	for(int i = 0; i < n - 1; i++) {
		scanf("%d", &q[i]);
		q[i]--;
	}

	for(int i = n - 2; i >= 0; i--)
	{
		merge(a[q[i]], b[q[i]], z[q[i]]);
		ans[i] = tot;
	}

	for(int i = 0; i < n - 1; i++)
		printf("%lld\n", ans[i]);
	printf("0");
}
