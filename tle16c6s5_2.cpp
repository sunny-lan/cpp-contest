#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

struct line {
	double b, m;
	double l, r;
};

inline bool pred1(const line &a, const  line &b) {
	return a.m > b.m;
}

inline bool pred2(const line &a,  double b) {
	return a.r < b;
}

inline double intersection(const line & a, const line & b) {
	return (b.b - a.b) / (a.m - b.m);
}

inline vector<line> preproc(vector<line> lines) {
	if (lines.empty())return lines;
	sort(lines.begin(), lines.end(), pred1);
	vector<line> res;
	lines[0].l = -INFINITY;
	res.push_back(lines[0]);
	int cust = (int)lines.size();
	for (int i = 1; i < cust; i++) {
		line& c = lines[i];
		while (true) {
			auto l = res.rbegin();
			double x = intersection(*l, c);
			if (l->l < x) {
				l->r = c.l = x;
				break;
			}
			res.pop_back();
		}
		res.push_back(c);
	}
	res[res.size() - 1].r = INFINITY;
	return res;
}

inline int findRange( double x,const vector<line> &lines) {
	int hi = lines.size(),
		lo = 0;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (lines[mid].r < x)
			lo = mid + 1;
		else if (lines[mid].l > x)
			hi = mid;
		else return mid;
	}
	return -1;
}

inline double f( double x, const vector<line> &lines) {
	const line & l = lines[findRange(x, lines)];
	return l.b + x*l.m;
}

typedef pair<int, int> pii;

#define MAXN 3000
#define MAXM 6001

vector<pii> adj[MAXN];

ll dp[MAXN][MAXM + 1];
bool lol[MAXN][MAXM + 1];
bool visited[MAXN];

int m;

void dfs(int i) {
	if (visited[i])return;
	visited[i] = true;
	if (i == 0) return;
		for (pii neigh : adj[i]) {
			for (int e = 1; e <= m; e++) {
				dfs(neigh.first);

				ll res = dp[i][e];
				if (!lol[neigh.first][e - 1])continue;

				ll alt = neigh.second + dp[neigh.first][e - 1];
				if (!lol[i][e] || alt < res) {
					dp[i][e] = alt;
					lol[i][e] = true;
				}
			}
		}
}

vector<line> costs[MAXN];

int main() {
	lol[0][0] = true;
	int n, d; scan(n); scan(m); scan(d);
	for (int i = 0; i < m; i++) {
		int u, v; ll t; scanf("%d %d %lld", &u, &v, &t);
		u--, v--;
		adj[v].push_back({ u,t });
	}


	for (int i = 0; i < n; i++) {
		dfs(i);
		for (int j = 0; j <= m; j++) {
			if (!lol[i][j])continue;
			ll res = dp[i][j];
			line l; l.m = j; l.b = res;
			costs[i].push_back(l);
		}
		costs[i] = preproc(costs[i]);
	}

	ll cs = 0;
	for (int i = 0; i < d; i++) {
		ll c; int dst; scanf("%lld %d", &c, &dst);
		cs += c;
		dst--;
		if (costs[dst].empty()) { printf("Cannot Deliver\n"); continue; }
		ll res = (ll)f(cs, costs[dst]);
		printf("%lld\n", res);
	}
	cin >> n;
}