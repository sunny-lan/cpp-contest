#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 751
#define MOD 1000000007

int bit[MAXN][MAXN];
void update( int row, int col, int v) {
	row = MAXN - row - 1;
	col = MAXN - col - 1;
	for(int i = row; i < MAXN; i += i & -i)
		for(int j = col; j < MAXN; j += j & -j)
			bit[i][j] += v,
						 bit[i][j] %= MOD;
}

int query( int row, int col) {
	row = MAXN - row - 1;
	col = MAXN - col - 1;
	int res = 0;
	for(int i = row; i > 0; i -= i & -i)
		for(int j = col; j > 0; j -= j & -j)
			res += bit[i][j],
				   res %= MOD;
	return res;
}

int r, c, k;
int num[MAXN][MAXN];
int dp[MAXN][MAXN];

vector<pii> fuk[2][MAXN * MAXN];
int dirty[MAXN * MAXN];
int csum[MAXN * MAXN];

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &r, &c, &k);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &num[i][j]), num[i][j]--;
	for(int i = 0; i < k; i++)
		dirty[i] = c - 2;
	dp[r - 1][c - 1] = 1;
	fuk[(c - 1) % 2][num[r - 1][c - 1]].push_back({r - 1, 1});
	for(int j = c - 2; j >= 0; j--) {
		int cidx = (j % 2);
		int pidx = (j + 1) % 2;
		for(int i = r - 2; i >= 0; i--) {
			int cust = query(i, j);
			auto &lst = fuk[pidx][num[i][j]];
			pii kust = {i, 0};
			pii rem = *lower_bound(lst.begin(), lst.end(), kust);
			dp[i][j] =  cust - rem.second;
			int cancer = rem.second;
			if(dirty[num[i][j]] != j) {
				csum[num[i][j]] = 0;
				dirty[num[i][j]] = j;
				fuk[cidx][num[i][j]].clear();
			}
			csum[num[i][j]]+=dp[i][j];
			cancer += csum[num[i][j]];
            fuk[cidx][num[i][j]].push_back({i, cancer});
		}
	}
	printf("%d\n", dp[0][0]);
}
