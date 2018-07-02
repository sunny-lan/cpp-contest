#include <bits/stdc++.h>
using namespace std;

#define MAXN 2005

int s[5], a[5];
int psa[MAXN];

int main() {
	int h, d, e;
	scanf("%d %d %d", &h, &d, &e);
	for(int i = 0; i < d; i++)
		scanf("%d %d", &a[i], &s[i]);
	for(int i = 0; i < e; i++) {
		int t, l, x;
		scanf("%d %d %d", &t, &l, &x);
		psa[t] += x;
		psa[t + l] -= x;
	}
	double tot = h;
	for(int i = 0; i < MAXN - 1; i++) {
		double mini = psa[i];
		for(int j = 0; j < d; j++) {
			double dmg = max(psa[i] - s[j], 0);
			dmg -= dmg*a[j]/100.0;
			mini = min(mini, dmg);
		}
		tot -= mini;
		psa[i + 1] += psa[i];
	}
	if(tot<=0.00000001)
        printf("DO A BARREL ROLL!\n");
    else
	printf("%.2lf\n", tot);
}
