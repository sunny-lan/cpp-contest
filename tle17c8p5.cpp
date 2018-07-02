#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 200001
#define MAXQ 100001
#define MAXK 51
#define MAXB 18

int a[MAXN];
int b[MAXK];
int sp[MAXB][MAXN];
int ans[MAXQ];
vector<pair<pii, int>> qu[MAXK];

int main() {
	memset(ans, -1, sizeof ans);
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	for(int i = 0; i < q; i++) {
		int j, l, r;
		scanf("%d%d%d", &j, &l, &r);
		j--, l--;
		qu[j].push_back({{l, r}, i});
	}
	for(int i = 0; i < k; i++) {
		memset(sp, -1, sizeof sp);
		int sm = 0;
		int r = 0;
		for(int l = 0; l < n; l++) {
			while(r < n && sm + a[r] <= b[i])
				sm += a[r], r++;
			if(a[l] <= b[i])
				sp[0][l] = r;
			sm -= a[l];
		}
		for(int j = n - 1; j >= 0; j--)
			for(int lv = 0; lv < MAXB - 1 && sp[lv][j] < n && sp[lv][j] != -1; lv++)
				sp[lv + 1][j] = sp[lv][sp[lv][j]];
		for(auto qr : qu[i]) {
			int l = qr.f.f, r = qr.f.s;
			int lvl = MAXB - 1, bs = 1 << lvl, cnt = 0;
			while(lvl >= 0 && l < r && l != -1)
				if(sp[lvl][l] == -1 || sp[lvl][l] > r)
					lvl--, bs >>= 1;
				else
					l = sp[lvl][l], cnt += bs;
			if(l < r)
				l = sp[0][l], cnt++;
			else
				ans[qr.s] = cnt;
		}
	}
	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}
