#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXV 102

int v[MAXN];

vector<int> child[MAXN];

bool dp[MAXN][MAXV];

bool qrange(int i, int l, int r) {
	if(l > v[i] || r < v[i])
		return false;
	return dp[i][l] && dp[i][r];
}

void calc(int i = 0) {
	for(int k : child[i])
		calc(k);
	dp[i][v[i]] = true;
	for(int j = v[i]; j < MAXV - 1; j++)
		if(dp[i][j])
			for(int k : child[i])
				if(v[k] > j)
					if(dp[k][j + 1])
						for(int l = v[k]; l < MAXV; l++)
							dp[i][l] |= dp[k][l];

	for(int j = v[i]; j > 0; j--)
		if(dp[i][j])
			for(int k : child[i])
				if(v[k] < j)
					if(dp[k][j - 1])
						for(int l = v[k]; l >= 0; l--)
							dp[i][l] |= dp[k][l];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]), v[i]--;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		child[a].push_back(b);
	}
	calc();
	int cnt = 0;
	for(int i = 0; i < MAXV; i++)
		for(int j = i  ; j < MAXV; j++)
			if(qrange(0, i, j))
				cnt++;
	printf("%d", cnt);
}
