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
#include <unordered_set>
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

#define MAXN 100000

int tohash(pii k) {
	return k.first*MAXN + k.second;
}

unordered_map<int, int> mentions[MAXN];
vector<int> adj[MAXN];

unordered_set<int> done;

int best[MAXN];

void doChain(pii curr) {
	if (done.find(tohash(curr)) != done.end())return;
	pii first = curr;
	unordered_map<int, int> last;
	int x = 0;
	bool mode = false;
	int chainsize;
	while (true) {
		int node = curr.first;
		if (mode) {
			if (last.find(node) != last.end()) {
				int lk = last[node];
				best[node] = max(best[node], x <= lk ? x - lk + chainsize : x - lk);
				last.erase(node);
			}
		}
		else {
			if (last.find(node) != last.end())
				best[node] = max(best[node], x - last[node]);
			last[node] = x;
		}
		done.insert(tohash(curr));
		int i = curr.first,
			p = curr.second,
			s = adj[i].size();
		int nxtIdx = (p - 1 + s) % s;
		int nxt = adj[i][nxtIdx];
		int jidx = mentions[i][nxt];
		curr = { nxt, jidx };
		x++;
		if (mode && curr == first)break;
		if (curr == first)mode = true, chainsize = x;
	}
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int k; scan(k);
		for (int j = 0; j < k; j++) {
			int c; scan(c); c--;
			adj[i].push_back(c);
			mentions[c][i] = j;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			doChain({ i, j });

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int r; scan(r); r--;
		printf("%d\n", best[r]);
	}

	cin >> q;
}