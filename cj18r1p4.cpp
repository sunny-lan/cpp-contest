#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		double a;
		scanf("%lf", &a);
		a /= 2;
		double ed = sqrt(0.5 - a * a);
		double x1 = a, y1 = -ed,
			   x2 = -a, y2 = ed,
			   x3 = ed, y3 = a,
			   mx1 = (x1 + x3) / 2.0,
			   my1 = (y1 + y3) / 2.0,
			   mx2 = (x2 + x3) / 2.0,
			   my2 = (y2 + y3) / 2.0;
        printf("Case #%d:\n", i);
        printf("%.9lf %.9lf 0\n", mx1, my1);
        printf("%.9lf %.9lf 0\n", mx2, my2);
        printf("0 0 0.5\n");
	}
}
