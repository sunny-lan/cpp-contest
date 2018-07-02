#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 256

vector<int> adj[MAXN];
bool visited[MAXN];
bool isset[MAXN];

set<int> dfs(int i) {
	set<int> res;
	if (visited[i])return res;
	visited[i] = true;
	char tmp = i + 'A';
	if (tmp >= 'a' && tmp <= 'z')
		res.insert(tmp-'A');
	else
		for (int neigh : adj[i]) {
			auto alt = dfs(neigh);
			res.insert(alt.begin(), alt.end());
		}
	return res;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string p, t, c; cin >> p >> t >> c;
		adj[p[0] - 'A'].push_back(c[0] - 'A');
		isset[p[0] - 'A'] = true;
		if (c[0] >= 'A' && c[0] <= 'Z')
			isset[c[0] - 'A'] = true;
	}

	for (char i = 'A'; i <= 'z'; i++) if (isset[i - 'A']) {
		cout << i << " = {";
		memset(visited, false, sizeof visited);
		auto res = dfs(i - 'A');
		int j = 0;
		for (int c : res) {
			cout << (char)(c + 'A');
			j++;
			if (j != res.size())
				cout << ",";
		}
		cout << "}\n";
	}

	cin >> n;
}