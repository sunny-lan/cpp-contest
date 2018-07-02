
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pair<bool, int>> pib;

unordered_map<int, vector<pib>> xlines;
unordered_map<int, vector<pib>> ylines;

#define MAXN 25000
bool bad[MAXN];

void chk(vector<pib> &evts) {
	sort(evts.begin(), evts.end());
	int cnt = 0, fline;
	for (pib evt : evts) {
		if (evt.second.first) {
			cnt++;
			if (cnt == 1)fline = evt.second.second;
			else if (cnt > 1) {
				bad[fline] = true;
				bad[evt.second.second] = true;
			}
		}
		else
			cnt--;
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		xlines[x1].push_back({ y1, {true,i} }); xlines[x1].push_back({ y2, {false,i} });
		xlines[x2].push_back({ y1, {true,i} }); xlines[x2].push_back({ y2, {false,i} });
		ylines[y1].push_back({ x1, {true,i} }); ylines[y1].push_back({ x2, {false,i} });
		ylines[y2].push_back({ x1, {true,i} }); ylines[y2].push_back({ x2, {false,i} });
	}

	for (auto x : xlines) chk(xlines[x.first]);
	for (auto y : ylines) chk(ylines[y.first]);

	int cnt = n;
	for (int i = 0; i< n; i++)if (bad[i])cnt--;

	printf("%d\n", cnt);

	cin >> n;
}