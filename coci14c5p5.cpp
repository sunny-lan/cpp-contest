#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int md[MAXN][MAXN];
int r, s;

void upd(int i, int j) {
	for(int k = 0; k < s; k++)
		md[i][k] = min(md[i][k], (k-j)*(k-j));
}

int qu(int i, int j) {
	int mini = INT_MAX;
	for(int k = 0; k < r; k++)
		mini = min(mini, md[k][j]+(k-i)*(k-i));
    return mini;
}

int main() {
	memset(md, 0x3f, sizeof md);
	scanf("%d%d", &r, &s);
	for(int i = 0; i < r; i++) {
		getchar();
		for(int j = 0; j < s; j++)
			if(getchar() == 'x')
				upd(i, j);
	}
	int g;
	scanf("%d", &g);
	for(int i = 0; i < g; i++) {
		int rr, ss;
		scanf("%d%d", &rr, &ss);
		rr--, ss--;
		printf("%d\n", qu(rr,ss));
		upd(rr,ss);
	}
}
