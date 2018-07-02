#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 1501

set<pii> rst[MAXN];
set<pii> cst[MAXN];

int upds[MAXN * MAXN];
pii pts[MAXN * MAXN];

int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	r--, c--;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			int v;
			scanf("%d", &v);
			pts[i * n + j] = {-v, i*n + j};
		}
	sort(pts, pts + n * n);
	for(int i = 0; i < n * n;) {
		int tmp = i;
		while(tmp < n * n && pts[tmp].f == pts[i].f)
		{
			int r1 = pts[tmp].s / n, c1 = pts[tmp].s % n;
			int res = 0;
			if(c1 > 0)
				for(pii x : cst[c1 - 1])
					if(abs(x.s - r1) > 1)
						res = max(res, x.f);
			if(c1 < n - 1)
				for(pii x : cst[c1 + 1])
					if(abs(x.s - r1) > 1)
						res = max(res, x.f);
			if(r1 > 0)
				for(pii x : rst[r1 - 1])
					if(abs(x.s - c1) > 1)
						res = max(res, x.f);
			if(r1 < n - 1)
				for(pii x : rst[r1 + 1])
					if(abs(x.s - c1) > 1)
						res = max(res, x.f);
			upds[tmp] = res + 1;
			if(r1==r &&c1==c){
                printf("%d", res+1);
                return 0;
			}
			tmp++;
		}
		for(int j = i; j < tmp; j++) {
			rst[pts[j].s / n].insert({upds[j], pts[j].s % n});
			if( rst[pts[j].s / n].size() > 4)
				rst[pts[j].s / n].erase(rst[pts[j].s / n].begin());
			cst[pts[j].s % n].insert({upds[j], pts[j].s / n});
			if( cst[pts[j].s % n].size() > 4)
				cst[pts[j].s % n].erase(cst[pts[j].s % n].begin());
		}
		i = tmp;
	}
}
