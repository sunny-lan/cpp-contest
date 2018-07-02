#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
using namespace std;

#define memeset memset
#define INF(a) (a==-1?INT_MAX:a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 4000
#define MAXM 20

#define MOD 1000000007

int x[MAXN];
int f[MAXN];

vector<double> trl[MAXN * 2];

int n;

void fill(int i) {
	if (trl[i].size() > 0)
		return;
	double center;
	if (i % 2 == 1)
		center = (x[i / 2] + x[(i + 1) / 2]) / 2;
	else
		center = x[i / 2];

	trl[i].push_back(0);

	for (int j = 0; j < n; j++)
		trl[i].push_back(trl[i][j] + f[j] * abs(x[j] - center));
}

int median[MAXN][MAXN + 1];

double dp[MAXN + 1][MAXM + 1];

inline void _main() {
	for (int i = 0; i < MAXN * 2; i++)
		trl[i].clear();
	memeset(median, 0, sizeof median);


	int m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		scan(x[i]);
		scan(f[i]);
		for (int j = 0; j <= m; j++)
			dp[i][j] = INFINITY;
	}
	for (int j = 0; j <= m; j++)
		dp[n][j] = INFINITY;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		int ptr = i;
		int hsum = 0;
		for (int j = i + 1; j <= n; j++) {
			sum += f[j - 1];
			int half = (sum - 1) / 2;
			while (hsum + f[ptr] <= half)
				hsum += f[ptr], ptr++;
			if (sum % 2 == 0)
				if (half + 1 == hsum + f[ptr]) {
					median[i][j] = ptr * 2 + 1;
					continue;
				}
			median[i][j] = ptr * 2;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int med = median[i][j];
			fill(med);
			for (int k = 0; k < m; k++)
				dp[j][k + 1] = min(dp[i][k] + trl[med][j] - trl[med][i], dp[j][k + 1]);
		}
	}

	cout << (ll)dp[n][m] % MOD << endl;
}

int main() {
	for (int testcase = 0; testcase < 10; testcase++) _main();
}