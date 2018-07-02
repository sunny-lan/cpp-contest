#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

struct vec {
	double x, y;
};

vec operator -(vec a, vec b) {
	return {a.x - b.x, a.y - b.y};
}

double cross(vec a, vec b) {
	return (a.x * b.y) - (a.y * b.x);
}

vec pt[MAXN];

bool pred(vec a, vec b) {
	vec da = a - pt[0], db = b - pt[0];
	double crs = cross(da, db);
	if(crs == 0)
		return da.x * da.x + da.y * da.y < db.x * db.x + db.y * db.y;
	return crs < 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &pt[i].x, &pt[i].y);
		if(i != 0)
			if(pt[i].y < pt[0].y || (pt[i].y == pt[0].y && pt[i].x < pt[0].x))
				swap(pt[i], pt[0]);
	}
	sort(pt + 1, pt + n, pred);
//	for(int i=0;i<n;i++)
//        printf("%lf %lf\n", pt[i]);
	vector<vec> s;
	s.push_back(pt[0]);
	s.push_back(pt[1]);
	for(int i = 2; i < n; i++) {
		vec p0 = pt[i];
		while(s.size() > 1 && cross(s[s.size() - 1] - s[s.size() - 2], p0 - s[s.size() - 1]) >= 0)
			s.pop_back();
		s.push_back(p0);
	}
//
//    cout <<"cust"<<endl;
//	for(vec v:s)
//        printf("%lf %lf\n", v);

	double a = 0;
	for(int i = 0; i < s.size() - 1; i++)
		a += s[i].x * s[i + 1].y - s[i + 1].x * s[i].y ;
	a = 0.5 * abs(a + s[s.size() - 1].x * s[0].y - s[0].x * s[s.size() - 1].y);
	printf("%d\n", (int)(a / 50));
}
