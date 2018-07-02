#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

string w[MAXN];
int c[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++)
		cin >> w[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	unordered_map<string, int> cst;
	for(int i = 0; i < k; i++) {
		int x;
		cin >> x;
		vector<int> cur;
		int mini = INT_MAX;
		for(int j = 0; j < x; j++) {
			int idx;
			cin >> idx;
			idx--;
			mini = min(c[idx], mini);
			cur.push_back(idx);
		}
		for(int j : cur)
			cst[w[j]] = mini;
	}
	ll tot = 0;
	for(int i = 0; i < m; i++) {
		string s;
		cin >> s;
		tot += cst[s];
	}
	printf("%I64d\n", tot);
}
