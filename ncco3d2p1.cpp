#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000
#define MAXB 16
int n, q;
int spa[MAXB][MAXN], spb[MAXB][MAXN];

void cons() {
	for(int lv = 1, bs = 2; bs <= n; lv++, bs <<= 1)
		for(int i = 0; i + bs <= n; i++)
			spa[lv][i] = min(spa[lv - 1][i], spa[lv - 1][i + bs / 2]),
						 spb[lv][i] = max(spb[lv - 1][i], spb[lv - 1][i + bs / 2]);
}

int cb(int x) {
	int res = 0;
	while(x = (x >> 1))
		res++;
	return res;
}

int qq(int l, int r) {
	int lv = cb(r - l);
	return max(spb[lv][l], spb[lv][r - (1 << lv)]) - min(spa[lv][l], spa[lv][r - (1 << lv)]);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &spa[0][i]), spb[0][i] = spa[0][i];
	cons();
	for(int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		printf("%d\n", qq(a, b));
	}
}
