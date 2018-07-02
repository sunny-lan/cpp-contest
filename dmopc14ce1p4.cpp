#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXV 1000
#define MAXE 1000

vector<pair<int, long double>> adj[MAXV];

int spd[MAXV][MAXV];
int dist[MAXV][MAXV];

pair<long double, int> du[MAXV];
bool visited[MAXV];

template <typename T>
bool less_int(T a, T b) {
	if (a == -1)
		return false;
	if (b == -1)
		return a != -1;
	return a < b;
}

bool less_pair(pair<long double, int> a, pair<long double, int> b) {
	if (a.first == b.first)
		return less_int(a.second, b.second);
	return less_int(a.first, b.first);
}

int main() {
	pair<long double,int> inf = { -1, -1 };
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < v; i++)
		du[i] = inf;
	for (int i = 0; i < e; i++) {
		int m, n;
		long double d, s;
		cin >> m >> n >> d >> s;
		n--, m--;
		long double t = (long double)d * 60.0 / (long double)s ;
		adj[m].push_back({ n,t });
		adj[n].push_back({ m,t });
		spd[m][n] = spd[n][m] = s;
		dist[m][n] = dist[n][m] = d*60;
	}

	du[0] = { 0, 0 };
	while (true) {
		int idx = -1;
		auto min = inf;
		for (int i = 0; i < v; i++) {
			if (visited[i]) continue;
			if (less_pair(du[i], min)) {
				min = du[i];
				idx = i;
			}
		}

		if (idx == -1)
			break;

		for (auto neigh : adj[idx]) {
			pair<long double, int> alt = { min.first + neigh.second,  min.second+1 };
			if (less_pair(alt, du[neigh.first])) {
				du[neigh.first] = alt;
			}
		}

		visited[idx] = true;
	}

	cout << du[v - 1].second << endl;

	cout << (int)round(du[v - 1].first/3) << endl;
	cin >> v;
	return 0;
}