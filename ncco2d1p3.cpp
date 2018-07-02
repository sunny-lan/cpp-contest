#include <bits/stdc++.cpp>
using namespace std;

typedef pair<int, char> pic;
#define f first
#define s second

#define MAXN 205

int n, m;
pic x[MAXN];

double rd;
double dp[MAXN][MAXN][MAXN];

double f(int i, int j, int k) {
	double &res = dp[i + 1][j + 1][k];
	if(res != -1)
		return res;
	res = INFINITY;
	int li = i == -1 ? x[k].f : x[i].f,
		lj = j == -1 ? x[k].f : x[j].f;
    //place in left moving track

	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	rd = 2 * m / (double)n;
	for(int i = 0; i < n; i++) {
		scanf("%d %c", &x[i].f, &dr[i].s);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				dp[i][j][k] = -1;
	}
	sort(x, x + n);
	printf("%.9lf", f(-1, -1, 0));
}
