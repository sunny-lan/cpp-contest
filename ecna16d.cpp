#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

#define MAXN 101

unordered_map<string, int> langs;
vector<pair<int, int>> adj[MAXN];

pair<int, int> du[MAXN];
bool visited[MAXN];

bool less_int(int a, int b) {
	if (a == -1)
		return false;
	if (b == -1)
		return a != -1;
	return a < b;
}

bool less_pair(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return less_int(a.second, b.second);
	return less_int(a.first, b.first);
}

int main() {
	pair<int, int> inf = { -1, -1 };
	int n, m;
	cin >> n >> m;
	n++;
	langs["English"] = 0;
	for (int i = 1; i < n; i++) {
		string lang;
		cin >> lang;
		langs[lang] = i;
		du[i] = inf;
	}
	for (int i = 0; i < m; i++) {
		string a, b;
		int c, d, f;
		cin >> a >> b >> c;
		d = langs[a]; f = langs[b];
		adj[d].push_back({ f, c });
		adj[f].push_back({ d, c });
	}
	du[0] = { 0, 0 };
	while (true) {
		int idx = -1;
		pair<int, int> min =inf;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			if (less_pair(du[i], min)) {
				min = du[i];
				idx = i;
			}
		}

		if (idx == -1)
			break;

		for (auto neigh : adj[idx]) {
			pair<int, int> alt = { min.first + 1,  neigh.second };
			if (less_pair(alt, du[neigh.first])) {
				du[neigh.first] = alt;
				src[neigh.first] = neigh.second;
			}
		}

		visited[idx] = true;
	}

	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (!visited[i]) {
			cout << "Impossible"<<endl;
			return 0;
		}
	}
	cout << sum << endl;
	cin >> n;
	return 0;
}