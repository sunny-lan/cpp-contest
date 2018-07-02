#include <bits/stdc++.h>
using namespace std;

bool cur[11][11];

int cnt[1 << 22];

void inv(int i, int j) {
	cur[i][j] = !cur[i][j];
	cur[i + 1][j] = !cur[i + 1][j];
	cur[i][j + 1] = !cur[i][j + 1];
	cur[i + 1][j + 1] = !cur[i + 1][j + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, g;
	cin >> n >> g;
	int tot = 0;
	for(int i = 0; i < g; i++) {
		for(int j = 0; j < n; j++)
		{
			string s;
			cin >> s;
			for(int k = 0; k < n; k++)
				cur[j][k] = (s[k] == 'R');
		}

		for(int k = 0; k < n - 1; k++)
			for(int l = 0; l < n - 1; l++)
				if(!cur[k][l])
					inv(k, l);

		int bm = 0;
		for(int k = 0; k < n; k++)
			bm |= cur[n - 1][k] << k;
		for(int k = 0; k < n; k++)
			bm |= cur[k][n - 1] << (k + n);
		tot += cnt[bm];
		cnt[bm]++;
	}
	printf("%d\n", tot);
}
