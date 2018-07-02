#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define f first
#define s second

#define MAXN 100000

int n, x;
int a[MAXN], b[MAXN];

ll wa() {
	multiset<pii> p;
	ll tot = 0;
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < n && a[j] < b[i])
			p.insert({a[j] % x, a[j]}), j++;
		auto kst = p.lower_bound({b[i] % x, -1});
		if(kst == p.end())
			kst = p.begin();
		int idx;
		if(kst == p.end())
			idx = a[j], j++;
		else
			idx = kst->s,
			p.erase(kst);
		tot += max(0, (b[i] - idx - 1) / x);
	}
	return tot;
}

int main() {
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	sort(a, a + n), sort(b, b + n);
	printf("%lld\n", wa());
}
