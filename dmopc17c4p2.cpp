#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000

int v[MAXN];
vector<int> adj[MAXN];
ll sum;
int len;
int y, op;
vector<int> kust;
unordered_map<int, int> cnt;
int best, maxi;
void proc(int i) {
	if (op == 1)sum += v[i], len++;
	else if (op == 2)
		kust.push_back(v[i]);
	else {
		++cnt[v[i]];
		if (cnt[v[i]] > maxi)
			maxi = cnt[v[i]], best = v[i];
		else if (cnt[v[i]] == maxi)
			if (v[i] < best)
				best = v[i];
		
	}
}
bool f(int i, int j = -1) {
	if (i == y) {
		proc(i); return true;
	}
	for (int k : adj[i])
		if (k != j)
			if (f(k, i)) {
				proc(i);
				return true;
			}
	return false;
}

int main() {
	int n, q; scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < q; i++) {
		int  x; scanf("%d %d %d", &op, &x, &y);
		x--, y--;
		if (op == 1) {
			sum = 0, len=0;
			f(x);
			printf("%d\n", (int)round((double)sum / len));
		}
		else if (op == 2) {
			kust = vector<int>();
			f(x);
			sort(kust.begin(), kust.end());
			if (kust.size() % 2 == 0)
				printf("%d\n", (int)round((kust[kust.size() / 2] + kust[kust.size() / 2 - 1]) / 2.0));
			else
				printf("%d\n", kust[kust.size() / 2]);
		}
		else {
			cnt = unordered_map<int, int>();
			maxi = -1;
			f(x);
			printf("%d\n", best);
		}
	}
	cin >> n;
}