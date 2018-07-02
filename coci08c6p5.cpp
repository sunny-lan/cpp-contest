#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXR 2005
#define MAXC 205
typedef long long ll;
int r, c;
int a[MAXR][MAXC];
int psa[MAXR][MAXC];
vector<pair<int, pii>> dst[MAXR];
bool inq[MAXR * 2];
int du[MAXR * 2];
priority_queue<pii> q;
inline void tins(int rw, int sd, int alt) {
	alt += a[rw][sd ? c - 1 : 0];
	int nd = rw * 2 + sd;
	if(inq[nd])return;
	if( alt < du[nd])
	{
		du[nd] = alt;
        q.push({-alt, nd});
	}
}
void dijk(int src) {
	memset(inq, false, sizeof inq);
	memset(du, 0x3f, sizeof du);
	q.push({0, src});
	du[src] = 0;
	while(!q.empty()) {
		int kst = q.top().s;
		q.pop();
		inq[kst] = true;
		int rw = kst / 2, sd = kst % 2;
		if(rw > 0)
			tins(rw - 1, sd, du[kst]);
		if(rw < r - 1)
			tins(rw + 1, sd, du[kst]);
		tins(rw, 1 - sd, du[kst] + psa[rw][c - 1] - psa[rw][1]);
	}
}

#define MAXD 200000

int ans[MAXD];

int main() {
//    freopen("C:\\Users\\Sunny\\Downloads\\contest6_testdata\\official_testdata\\dostava\\dostava.in.9", "r", stdin);
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &a[i][j]),
//a[i][j]=rand()%5000,
				  psa[i][j + 1] = psa[i][j] + a[i][j];
	int d;
	scanf("%d", &d);
	int cr = 0, cc = 0;

	for(int i = 0; i < d; i++) {
		int a, b;
//		a=rand()%r,b=rand()%c;
		scanf("%d %d", &a, &b);
		a--, b--;
		dst[cr].push_back({cc, {a, b}});
		cr = a, cc = b;
	}

	ll tot = 0;
	//s=1 -> c=c s=0 -> c=0
	for(int dr=0;dr<r;dr++) {
//        printf("proc %d\n", dr);
		auto &lol=dst[dr];
		dijk(dr * 2);
		for(int i = 0; i < lol.size(); i++) {
			auto x = lol[i];
			ans[i] = min(du[x.s.f * 2] + psa[x.s.f][x.s.s + 1] - psa[x.s.f][1],
						 du[x.s.f * 2 + 1] + psa[x.s.f][c - 1] - psa[x.s.f][x.s.s])
					 + psa[dr][x.f];
			if(x.s.f == dr) {
				if(x.f < x.s.s)
					ans[i] = min(ans[i], psa[dr][x.s.s + 1] - psa[dr][x.f + 1]);
				else
					ans[i] = min(ans[i], psa[dr][x.f] - psa[dr][x.s.s]);
			}
		}
		dijk(dr * 2 + 1);
		for(int i = 0; i < lol.size(); i++) {
			auto x = lol[i];
			tot += min(ans[i],
					   min(du[x.s.f * 2] + psa[x.s.f][x.s.s + 1] - psa[x.s.f][1],
						   du[x.s.f * 2 + 1] + psa[x.s.f][c - 1] - psa[x.s.f][x.s.s])
					   + psa[dr][c] - psa[dr][x.f + 1]);
		}
	}

	printf("%lld\n", tot + a[0][0]);
}
