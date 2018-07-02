#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

#define MAXN 19
#define CUST 1<<MAXN

int n;

int adj[MAXN][MAXN];

int dp[MAXN][CUST];
bool p[MAXN][CUST];

int f(int i, int v) {
	//cout << "at node " << i << endl;
	if (i == 0) {
		return 0;
	}
	int res = dp[i][v];
	if (p[i][v])
		return res;

	res = -1;

	for (int j = 0; j < n; j++)
		if (adj[i][j] != 0) {
			if (((v >> j) & 1) == 0) {
				int alt = f(j, v | 1 << j);
				if (alt != -1)
					res = max(res, alt + adj[i][j]);
			}
		}



	dp[i][v] = res;
	p[i][v] = true;
	//cout << "ret node " << i << endl;
	return res;
}

int main() {

	int  m;
	cin >> n >> m;
	memset(adj, 0, sizeof(adj));

	for (int i = 0; i < m; i++) {
		int s, d, l;
		cin >> s >> d >> l;
		adj[d][s] = l;
	}
	cout << f(n - 1, 1 << (n - 1)) << endl;
	//cin >> n;
}