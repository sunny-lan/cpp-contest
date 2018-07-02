#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 2001

struct T2 {
	int a, b;

	bool operator < (const T2& in) const
	{
		return (b < in.b);
	}
};

vector<vector<T2>> adj;

int x[MAXN];
int y[MAXN];
int dists[MAXN];

unordered_map<int, unordered_map<int, int>> dp;

void add(int n, int dist, int val) {
	dp[n][dist] = val;
}

int get(int n, int dist) {
	if (dp.find(n) == dp.end())
		return -1;
	if (dp[n].find(dist) == dp[n].end())
		return -1;
	return dp[n][dist];
}

int maxi(int n, int dist) {
	int ret = get(n, dist);
	if (ret == -1) {
		ret = 0;
		for (T2 neigh : adj[n]) {
			if (neigh.b >= dist)
				break;
			ret = max(ret, maxi(neigh.a, neigh.b) + 1);
		}
		add(n, dist, ret);
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		vector<T2> arr;
		int ax = x[i];
		int ay = y[i];
		{
			int dx = abs(ax);
			int dy = abs(ay);
			dists[i] = dx*dx + dy*dy;
		}

		for (int j = 0; j < n; j++) {
			if (j != i) {
				int dx = abs(ax - x[j]);
				int dy = abs(ay - y[j]);
				T2 res = { j,dx*dx + dy*dy };
				arr.push_back(res);
			}
		}

		sort(arr.begin(), arr.end());

		adj.push_back(arr);
	}

	int maxim = 0;
	for (int i = 0; i < n; i++) {
		maxim = max(maxim, maxi(i, dists[i]) + 1);
	}
	cout << maxim << endl;

	return 0;
}