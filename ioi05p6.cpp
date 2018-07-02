#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 101
#define MAXK 51
#define INF 0x3f3f3f3f3f3f3f3fll

int n, kk;
vector<pii> chi[MAXN];
int w[MAXN];

ll dp[MAXN][MAXN][MAXK];
ll tmp[MAXK];
bool v[MAXN][MAXN];
void calc(int i = 0, int j = 0, int d = 0) {
	if(v[i][j])
		return;
	v[i][j] = true;

	for(pii k : chi[i])
		calc(k.f, j, d + k.s), calc(k.f, i, k.s);

	memset(tmp, 0x3f, sizeof tmp);
	dp[i][j][0] = d * w[i];
	tmp[0] = 0;

	for(pii k : chi[i]) {
		for(int l = kk; l >= 0; l--) {
			ll mina = INF, minb = INF;
			for(int m = 0; m <= l; m++)
				mina = min(mina, dp[k.f][j][m] + dp[i][j][l - m]),
				minb = min(minb, dp[k.f][i][m] + tmp[l - m]);
			dp[i][j][l] = mina;
			tmp[l] = minb;
		}
	}

	for(int l = 1; l <= kk; l++)
		dp[i][j][l] = min(dp[i][j][l], tmp[l - 1]);
}

int main() {
	memset(dp, 0x3f, sizeof dp);
	scanf("%d%d", &n, &kk);
	n++;
	for(int i = 1; i < n; i++) {
		int v, d;
		scanf("%d%d%d", &w[i], &v, &d);
		chi[v].push_back({i, d});
	}
	calc();
	printf("%lld\n", dp[0][0][kk]);
}
