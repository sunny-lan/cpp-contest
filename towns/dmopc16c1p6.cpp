#include <bits/stdc++.h>
using namespace std;

#define MAXN 500
#define MAXB 30

typedef bitset<MAXN> vec;

int a[MAXN];

vec mpow[MAXB][MAXN], tmp[MAXN];
int n, m;

void transpose(vec *a, vec *b) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			b[i][j] = a[j][i];
}
void mult(vec *a, vec *b, vec *c) {
	transpose(a, tmp);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			c[i][j] = (tmp[j] & b[i]).count() > 0;
}

vec mult(vec *a, vec x) {
	vec y;
	for(int i = 0; i < n; i++)
		if(x[i])
			y |= a[i];
	return y;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		mpow[0][u][v] = 1;
	}

	for(int i = 1; i < MAXB; i++)
		mult(mpow[i - 1], mpow[i - 1], mpow[i]);

	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int c, k;
		scanf("%d %d", &c, &k);
		int tk=k;
		c--;
		vec x;
		x[c] = 1;
		for(int j = 0; k; k >>= 1, j++)
			if(k & 1)
				x = mult(mpow[j], x);
		vec acc;
		vec y;
		y[c] = 1;
        acc = y;
        vec lst;
		for(int j = 0; j < min(tk, n); j++)
		{
			y = mult(mpow[0], y);
            acc |= y;
            if(acc==lst)break;
            lst=acc;
		}
		int mini = INT_MAX;
		for(int i = 0; i < n; i++)
			if(acc[i])
				mini = min(mini, a[i]);
		printf("%d %d\n", mini, x.count());
	}
}
