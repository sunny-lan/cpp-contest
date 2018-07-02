#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <regex>
#include <functional>
#include <queue>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef pair<int, int> pii;

#define MAXN 500

regex re("\\b[Pp]rincess\\b");

vector<int> gs;

vector<int> gg[MAXN + 10];

bool cmp(int a, int b) {
	if (a == -1)
		return false;
	if (b == -1)
		return true;
	if (gs[a] == gs[b])
		return a < b;
	return gs[a] > gs[b];
}
int ans[MAXN + 10];
bool _cmp(int a, int b) {
	return cmp(ans[a], ans[b]);
}

int k[MAXN+10];

int main() {
	memset(ans, -1, sizeof ans);

	int p; cin >> p; ws(cin);
	gs.push_back(0);
	for (int i = 0; i < p; i++) {
		string name; getline(cin, name);
		int match_count = distance(
			sregex_iterator(name.begin(), name.end(), re),
			sregex_iterator());
		if (match_count != 1) {
			if (gs.back() != 0)gs.push_back(0);
			continue;
		}
		gs[gs.size() - 1] = gs.back() + 1;
	}
	if (gs.back() == 0)
		gs.pop_back();
	int g = gs.size();

	for (int i = 0; i < g; i++) {
		cin >> k[i];
		gg[k[i]].push_back(i);
	}

	priority_queue<int, vector<int>, function<bool(int, int)>> q(_cmp);
	for (int i = 0; i <= MAXN; i++) {
		for (int tg : gg[i]) if (!q.empty()) {
			int ng = q.top();

			if (cmp(tg, ans[ng])) {
				q.pop();
				ans[ng] = tg;
				q.push(ng);
			}
		}
		q.push(i);
	}

	while (true) {
		for (int i = 0; i <= MAXN+1; i++) {
			for (int j = 0; j < i; j++) {
				if (ans[i] == -1 || ans[j] == -1)
					continue;
				if (i >= k[ans[j]]) continue;
				if (_cmp(i, j)) {
					int tmp = ans[i];
					ans[i] = ans[j];
					ans[j] = tmp;
					goto d;
				}

			}
		}
		break;
	d: continue;
	}

	for (int i = 0; i <= MAXN; i++)
		if (ans[i] != -1)
			cout << ans[i] + 1 << endl;

	cin >> p;
}