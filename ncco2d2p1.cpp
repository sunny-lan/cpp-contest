#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pll vec;
#define x first
#define y second

typedef pair<vec, vec> ln;
#define p first
#define q second

#define EPS 0.0001

vec operator -(vec a, vec b) {
	return {a.x - b.x, a.y - b.y};
}
vec operator +(vec a, vec b) {
	return {a.x + b.x, a.y + b.y};
}

bool operator ==(pdd a, pdd b) {
	return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}

#define MAXN 1500

vec pts[MAXN];

inline ll crs(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

inline ln nrm(ln a) {
	if(a.p.x < a.q.x)
		swap(a.p, a.q);
	return a;
}

inline ll lcrs(ln a, ln b) {
	return crs(a.p - a.q, b.p - b.q);
}

bool pred(ln a, ln b) {
	return lcrs(a, b) < 0;
}

inline pdd rot(vec p, double ang) {
	double s = sin(ang), cs = cos(ang);
	return {p.x * cs - p.y * s, p.x * s + p.y * cs};
}


pair<pdd, double> grp[MAXN * MAXN / 2];
ln lns[MAXN * MAXN / 2];
int main() {
	int n;
	scanf("%d", &n);
	int idx = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &pts[i].x, &pts[i].y);
		for(int j = 0; j < i; j++)
			if(pts[i] != pts[j])
				lns[idx++] = nrm({pts[i], pts[j]});
	}
	double maxi = 0;
	sort(lns, lns + idx, pred);

	for(int i = 0; i < idx;) {
		ln tmp = lns[i];
		vec c = tmp.p, d = c - tmp.q;
		double ang = -atan(d.y / (double)d.x);
		int ddx = 0;
		while(i < idx && lcrs(tmp, lns[i]) == 0)
		{
			pdd a = rot(lns[i].p - c, ang), b = rot(lns[i].q - c, ang);
			grp[ddx++] = {{min(a.x, b.x), max(a.x, b.x)}, a.y}; //ay should == by
			i++;
		}
		sort(grp, grp + ddx);
		for(int j = 0; j < ddx;) {
			auto fst = grp[j];
			while(j < ddx && fst.first == grp[j].first) {
				maxi = max(maxi, abs( (fst.second - grp[j].second) * (fst.first.first - fst.first.second)));
				j++;
			}
		}
	}
	printf("%.0lf\n", maxi);
}
