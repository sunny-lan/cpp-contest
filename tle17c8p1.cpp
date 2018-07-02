#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double t1 = INFINITY;
	for(int i = 0; i < n; i++) {
		double x, tx;
		scanf("%lf%lf", &x, &tx);
		if(x == 0) {
			if(tx == 0)
				continue;
			else {
				printf("no\n");
				return 0;
			}
		}
		if(t1 == INFINITY)
			t1 = tx / x;

		if(t1 != INFINITY)
			if(abs(t1 * x - tx) > 0.000000001) {
				printf("no\n");
				return 0;
			}
	}
	printf("yes\n");
}
