#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXK 41

int cnt[MAXK];
double tot[MAXK];

int main() {
	int n, k, l;
	scanf("%d %d %d", &n, &k, &l);
	vector<pii> fwd, bkd;
	for(int i = 0; i < n; i++) {
		int d, b;
		char c;
		scanf("%d %d %c", &d, &b, &c);
		if(c == 'L')
			bkd.push_back({d, b});
		else
			fwd.push_back({d, b}),
						  tot[b] += l - d;
	}
	int lp = -1, j = 0, cof = 0;
	for(pii c : bkd) {
		while(j < fwd.size() && fwd[j].f <= c.f) {
			if(lp != -1)
				cnt[cof] += fwd[j].f - lp;
			lp = fwd[j].f;
			cof += fwd[j].s, cof %= k;
			j++;
		}
		if(lp != -1)
			cnt[cof] += c.f - lp, lp = c.f;
		for(int i = 0; i < k; i++)
//            printf("tot[%d]+=(cnt[%d]=%d)/2\n", i, (c.s+cof-i+k)%k, cnt[(c.s+cof-i+k)%k]),
			tot[i] += cnt[(c.s + cof - i + k) % k] / 2.0;
		if(c.f > fwd[0].f)
			tot[(cof + c.s) % k] += (fwd[0].f + c.f) / 2.0;
		else
			tot[c.s] += c.f;
	}
	for(int i = 0; i < k; i++)
		printf("%.1lf\n", tot[i]);
}
