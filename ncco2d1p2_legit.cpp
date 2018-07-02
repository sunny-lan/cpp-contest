#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100001

pair<pii, int> t[MAXN];
int ans[MAXN];

vector<set<pii>> lns;
int i;

bool f(int j) {
	if(j == lns.size())
		return true;
	set<pii> &ln = lns[j];
	auto cr = ln.lower_bound({t[i].f.s, -1});
	if(cr != ln.end())
		if(abs(cr->f - t[i].f.s) < abs(cr->s - t[i].f.f))
			return false;
	if(cr != ln.begin()) {
		cr = prev(cr);
		if(abs(cr->f - t[i].f.s) < abs(cr->s - t[i].f.f))
			return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for( i = 0; i < n; i++)
		scanf("%d%d", &t[i].f.f, &t[i].f.s), t[i].s = i;
	sort(t, t + n);
	for( i = 0; i < n; i++) {
		int lo = 0, hi = lns.size() + 1;
		while(lo < hi) {
			int mid = (lo + hi) / 2;
			if(f(mid))
				hi = mid;
			else
				lo = mid + 1;
		}
		if(lo == lns.size()) {
			ans[t[i].s] = lns.size();
			lns.push_back({{t[i].f.s, t[i].f.f}});
		} else {
			lns[lo].insert({t[i].f.s, t[i].f.f});
			ans[t[i].s] = lo;
		}
	}
	printf("%d\n", lns.size());
	for( i = 0; i < n; i++)
		printf("%d\n", ans[i] + 1);
}
