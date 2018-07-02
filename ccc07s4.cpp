#include <iostream>
#include <vector>

using namespace std;

#define MAXN 10000

int n, x, y;

vector<int> adj[MAXN];

int dp[MAXN];

int f(int i) {
	int res = dp[i];
	if (res != -1)
		return res;
	if (i == 0)
		res = 1;
	else {
		res = 0;
		for (int neigh : adj[i]) {
			res += f(neigh);
		}
	}
	dp[i] = res;
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		dp[i] = -1;
	while (true) {
		cin >> x >> y;
		if (x == 0 && y == 0)
			break;
		x--;
		y--;
		adj[y].push_back(x);
	}
	cout << f(n - 1) << endl;
	cin >> n;
}