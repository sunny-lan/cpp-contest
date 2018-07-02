#include <bits/stdc++.h>
using namespace std;

struct vec {
	double x, y;
};
vec operator -(vec a, vec b) {
	return {a.x - b.x, a.y - b.y};
}
double cross(vec a, vec b) {
	return (a.x * b.y) - (a.y * b.x);
}
double dist(vec a, vec b) {
	vec d = a - b;
	return sqrt(d.x * d.x + d.y * d.y);
}
struct line {
	double a, b, c;
	line(vec p, vec q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -(p.x * a + p.y * b);
	}
};
double dist(line l, vec q) {
	return abs(l.a * q.x + l.b * q.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
vec closest(line l, vec q) {
	double den = l.a * l.a + l.b * l.b;
	return {(l.b * (l.b * q.x - l.a * q.y) - l.a * l.c) / den,
			(l.a * (l.a * q.y - l.b * q.x) - l.b * l.c) / den};
}
double lval(line l, vec a, vec b, vec q) {
	vec cls = closest(l, q);
	double da = dist(cls, a), db = dist(cls, b), dab = dist(a, b);
	if(da < dab && db < dab)
		return -da;
	if(da < db)
		return da;
	else
		return -da;
}

#define MAXN 100001

vec pt[MAXN];
bool pred(vec a, vec b) {
	vec da = a - pt[0], db = b - pt[0];
	double crs = cross(da, db);
	if(crs == 0)
		return da.x * da.x + da.y * da.y < db.x * db.x + db.y * db.y;
	return crs < 0;
}
vector<vec> hul;
vec gt(int idx) {
	return hul[(idx + hul.size()) % hul.size()];
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &pt[i].x, &pt[i].y);
		if(i != 0)
			if(pt[i].y < pt[0].y || (pt[i].y == pt[0].x && pt[i].x < pt[0].x))
				swap(pt[i], pt[0]);
	}
	sort(pt + 1, pt + n, pred);
	hul.push_back(pt[0]), hul.push_back(pt[1]);
	for(int i = 2; i < n; i++)
	{
		while(hul.size()>1 && cross(hul[hul.size() - 1] - hul[hul.size() - 2], pt[i] - hul[hul.size() - 1]) >= 0)
			hul.pop_back();
		hul.push_back(pt[i]);
	}
	double res = INFINITY ;
	int p1 = 0, p2 = 0, p3 = 0;
	for(int i = 0; i < hul.size(); i++) {
		vec a = gt(i), b = gt(i + 1);
		line l(a, b);
		double d1, d2, d3;
		while((d1 = lval(l, a, b, gt(p1))) > lval(l, a, b, gt(p1 + 1)))
			p1++;
		p2 = max(p2, p1);
		while((d2 = dist(l, gt(p2))) < dist(l, gt(p2 + 1)))
			p2++;
		p3 = max(p3, p2);
		while((d3 = lval(l, a, b, gt(p3))) < lval(l, a, b, gt(p3 + 1)))
			p3++;
		res = min(res, (abs(d1) + abs(d3)) * abs(d2));
	}
	printf("e%.0lf", res);
}
