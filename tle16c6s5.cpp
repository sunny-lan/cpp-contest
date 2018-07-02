#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <float.h>

using namespace std;

#define MAXN 3001
#define MAXM 6001

double intersection(int m, long b, int n, long c) {
	return ((double)c - (double)b) / ((double)m - (double)n);
}

unordered_map<int, long> adj[MAXN];
long dp[MAXN][MAXM];
bool visited[MAXN][MAXM];
vector<pair<int, long>> best[MAXN];

vector<double> ints[MAXN];
vector<pair<int, long>> points[MAXN];

long f(int i, int j) {
	if (visited[i][j])
		return dp[i][j];

	long res = LONG_MAX;
	if (j == 0) {
		if (i == 0)
			res = 0;
	}
	else {
		for (auto neigh : adj[i]) {
			long alt = f(neigh.first, j - 1);
			if (alt != LONG_MAX)
				res = min(res, alt + neigh.second);
		}
	}

	dp[i][j] = res;
	visited[i][j] = true;

	if (res != LONG_MAX)
		best[i].push_back(make_pair(j, res));

	return res;
}

int main() {
	int n, m, q, u, v;
	long t;
	cin >> n >> m >> q;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		u--;
		v--;
		long oldval = LONG_MAX;
		if (adj[v].find(u) != adj[v].end())
			oldval = adj[v][u];
		adj[v][u] = min(oldval, t);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++)
			f(i, j);

		sort(best[i].begin(), best[i].end());

		if (best[i].size() == 0)
			continue;

		double lastInt = -DBL_MAX;
		pair<int, long> lastCrossed;
		for (int idx = best[i].size() - 2; idx >= 0; idx--) {
			double inter = intersection(best[i][idx + 1].first, best[i][idx + 1].second, best[i][idx].first, best[i][idx].second);
			if (inter >= lastInt) {
				ints[i].push_back(lastInt);
				points[i].push_back(best[i][idx + 1]);
				lastInt = inter;
				lastCrossed = best[i][idx + 1];
			}
			else {
				lastInt = intersection(lastCrossed.first, lastCrossed.second, best[i][idx].first, best[i][idx].second);
			}
		}
		ints[i].push_back(lastInt);
		points[i].push_back(best[i][0]);
	}

	long c = 0;
	for (int i = 0; i < q; i++) {
		long x, d;
		cin >> x >> d;
		c += x;
		d--;
		auto up = upper_bound(ints[d].begin(), ints[d].end(), (double)c);
		const bool found = up != ints[d].end() && *up == c;
		if (!found) {
			cout << "Cannot Deliver" << endl;
			continue;
		}
		pair<int, long> pt = points[d][up- ints[d].end()];
		long output = pt.first*c + pt.second;
		cout << output << endl;
	}
}