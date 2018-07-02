#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int y, z;
		scanf("%d %d", &y, &z);
		double hi = z, lo = 0;
		for(int j = 0; j < 50; j++) {
			double x = (hi + lo) / 2;
			double pw = x;
			for(int k = 0; k < y - 1; k++)
			{
				if(pw > z) {
					hi = x;
					goto outer;
				}
				pw = pow(x, pw);
			}
            if(pw > z)
					hi = x;
					else
                        lo=x;
		outer:
			continue;
		}
		printf("%.9lf\n", lo);
	}
}
