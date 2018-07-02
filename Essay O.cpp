
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


#ifdef DMOJ
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
auto findKth(ordered_set<T> s, int k) {
	if (k >= s.size())return s.end();
	return s.find_by_order(k);
}

template <typename T>
auto getRank(ordered_set<T> s, T k) {
	return s.order_of_key(k);
}
#else
#include <set>

template <typename T>
using ordered_set = set<T>;

template <typename T>
auto findKth(ordered_set<T> &s, int k) {
	if (k >= s.size())return s.end();
	auto tmp = s.begin();
	advance(tmp, k);
	return tmp;
}

template <typename T>
auto getRank(ordered_set<T> &s, T k) {
	int cnt = 0;
	for (T c : s) {
		if (c == k)break;
		cnt++;
	}
	return cnt;
}
#endif // DMOJ

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int p[MAXN];
int deg[MAXN];
vector<int> child[MAXN];

int h[MAXN];
int special[MAXN];

int dfs(int i) {
	int sz = 1;
	int maxi = -1;
	for (int j : child[i]) {
		h[j] = h[i] + 1;
		int alt = dfs(j);
		if (alt > maxi)
			maxi = alt, special[i] = j;
		sz += alt;
	}
	return sz;
}

#define THETA 100000

int pchain[MAXN];
int chain[MAXN];
int chid = 0;
ordered_set<pair<double, int>> nodes[MAXN];
double mapping[MAXN];
int hchain[MAXN];

void hld(int i, bool cust) {
	if (cust)
		pchain[chid++] = chain[p[i]], hchain[chid] = h[i];

	chain[i] = chid;
	nodes[chid].insert({ mapping[i] = THETA*h[i], i });

	if (child[i].size() > 0)
		hld(special[i], false);
	for (int k : child[i])if (k != special[i])
		hld(k, true);
}

int main() {
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		p[b] = a;
		child[a].push_back(b);
		deg[b]++;
	}
	int root;
	for (int i = 0; i < n; i++)
		if (deg[i] == 0) {
			root = i; break;
		}

	dfs(root);
	hld(root, true);

	for (int i = 0; i < q; i++) {
		int op, p; scan(op); scan(p);
		if (op == 1) {
			int r; scan(r);
			int curr = chain[p];
			while (true) {
				auto &cchain = nodes[curr];
				int chsz = cchain.size();
				if (curr == chain[p]) {
					int rnk = getRank(cchain, { mapping[p], p });
					chsz = rnk;
					nodes[curr].erase({ mapping[p], p });
				}
				if (chsz >= r) {
					auto kth = findKth(cchain, chsz - r);
					chain[p] = curr;
					double pmap;
					if (kth == cchain.end()) {
						cchain.insert({ mapping[p] = 0, p });
						break;
					}
					if (kth == cchain.begin())
						pmap = cchain.begin()->first - THETA * 2;
					else
						pmap = prev(kth)->first;
					cchain.insert({ mapping[p] = (pmap + kth->first) / 2, p });
					break;
				}
				auto &nchain = nodes[pchain[curr]];
				auto beg = nchain.begin();
				int shiftednode = beg->second;
				nchain.erase(beg);

				double nmap = 0;
				if (!cchain.empty())
					nmap = cchain.rbegin()->first + THETA;
				cchain.insert({ mapping[shiftednode] = nmap, shiftednode });
				chain[shiftednode] = curr;
				r -= chsz;
				curr = pchain[curr];
			}
		}
		else {
			int curr = chain[p];
			int currh = hchain[curr];
			printf("%d\n", currh + getRank(nodes[curr], { mapping[p], p }));
		}
	}
}