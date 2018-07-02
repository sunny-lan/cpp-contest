#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <set>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 10000

set<double> dp[MAXN + 1];

int p[MAXN];

double x[MAXN];
double y[MAXN];

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++)
		scan(p[i]);

	for (int i = 0; i < n; i++) {
		if (i + 3 <= n)
			x[i] = p[i] + p[i + 1] + p[i + 2] - min(min(p[i], p[i + 1]), p[i + 2]);
		if (i + 2 <= n)
			y[i] = p[i] + p[i + 1] - min((double)p[i], (double)p[i + 1]) / 2;
	}

	dp[0].insert(0);

	for (int i = 0; i < n; i++)
	{
		auto e = dp[i].begin();
		for (int j = 0; j < k; j++) {
			if (e == dp[i].end())break;
			double v = *e;
			dp[i + 1].insert(v + p[i]);
			if (i + 3 <= n)
				dp[i + 3].insert(v + x[i]);
			if (i + 2 <= n)
				dp[i + 2].insert(v + y[i]);
			e++;
		}
		dp[i] = set<double>();
	}

	if ((int)dp[n].size() < k)
		printf("-1\n");
	else {
		auto it = dp[n].begin(); advance(it, k - 1);
		printf("%.1f\n", *it);
	}
	cin >> n;
}