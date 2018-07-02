#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> conn;
#define f first
#define s second

#define EPS 0.00000000001
#define MAXN 700
#define MAXNN MAXN*MAXN

bool eq(double a, double b) {
	return abs(a - b) < EPS;
}

int h[MAXN][MAXN];
int v[MAXN][MAXN];

int n;
bool bnd(int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= n;
}

double cinter(int i1, int j1, int i2, int j2) {
	int h1 = h[i1][j1], v1 = v[i1][j1],
		h2 = h[i2][j2], v2 = v[i2][j2];
	return (h2 - h1) / (double)(v1 - v2);
}

int p2[MAXNN], sz2[MAXNN];
int f2(int x) {
	if(p2[x] == x)
		return x;
	return p2[x] = f2(p2[x]);
}

int nid(int i, int j) {
	return f2(i * n + j);
}

vector<conn> kst;
void pinter(int i1, int j1, int i2, int j2) {
	if(bnd(i1, j1) || bnd(i2, j2))
		return;
	double rs = cinter(i1, j1, i2, j2);
	int a = nid(i1, j1), b = nid(i2, j2);
	if(a == b)
		return;
	if(rs != rs)
		p2[a] = b, sz2[b] += sz2[a], sz2[a] = 0;
	if(isfinite(rs))
		kst.push_back({rs, {a, b}});
}

int t;

int p[MAXNN], d[MAXNN];
int sz[MAXNN];

void init(int x) {
	if(d[x] != t)
		p[x] = x, sz[x] = sz2[x], d[x] = t;
}

int f(int x) {
	init(x);
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}

int maxi = 1;
void mrg(int x, int y) {
	int px = f(x), py = f(y);
	if(px == py)
		return;
	p[px] = py;
	sz[py] += sz[px];
	maxi = max(maxi, sz[py]);
	sz[px] = 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			p2[i * n + j] = i * n + j, sz2[i * n + j] = 1,
							scanf("%d", &h[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			pinter(i, j, i + 1, j);
			pinter(i, j, i, j + 1);
		}
	sort(kst.begin(), kst.end());

	for(int i = 0; i < kst.size();) {
		double tmp = kst[i].f;
		t++;
		while(i < kst.size() && eq(tmp, kst[i].f)) {
			auto c = kst[i].s;
			mrg(f2(c.f), f2(c.s));
			i++;
		}
	}

	printf("%d", maxi);
}
