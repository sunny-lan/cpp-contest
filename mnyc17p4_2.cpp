#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1010

int v[MAXN];

int dp[MAXN][MAXN];

vector<int> locs[MAXN];
int idxs[MAXN];

int f(int i, int j) {
	if (j - i <= 1)return 0;
	int res = dp[i][j];
	if (res != -1)return res;
	res = min(f(i + 1, j) + 1, f(i, j - 1) + 1);
	for (int k = idxs[i]+1; k < locs[v[i]].size() && locs[v[i]][k] < j; k++)
		res = min(res, f(i, locs[v[i]][k]) + f(locs[v[i]][k], j));
	dp[i][j] = res;
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);

	int n; scan(n);
	for (int i = 1; i < n + 1; i++)
		scan(v[i]);

	v[0] = 0;
	v[n + 1] = n + 1;

	for (int i = 0; i < n + 2; i++) {
		idxs[i] = locs[v[i]].size();
		locs[v[i]].push_back(i);
	}

	int res = f(0, n + 1);
	printf("%d\n", res);
	cin >> n;
}