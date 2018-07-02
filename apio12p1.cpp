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

#define MAXN 100001

ll m;

int b[MAXN];
int l[MAXN];

priority_queue<int> pq[MAXN];
ll cnt[MAXN];

ll maxi = 0;

void merge(int a, int b) {
	if (a == b)return;
	if (pq[b].size() < pq[a].size()) {
		swap(pq[a], pq[b]);
		swap(cnt[a], cnt[b]);
	}
	while (!pq[a].empty()) {
		pq[b].push(pq[a].top());
		cnt[b] += pq[a].top();
		pq[a].pop();
	}
	while (cnt[b] > m)
		cnt[b] -= pq[b].top(), pq[b].pop();

	cnt[a] = 0;
}

int main() {
	int n; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		int c; scan(b[i]); scan(c); scan(l[i]);
		b[i]--;
		pq[i].push(c);
		cnt[i] = c;
	}

	for (int i = n - 1; i >= 0; i--) {
		maxi = max(maxi, (ll)pq[i].size()*l[i]);
		merge(i, b[i]);
	}
	
	printf("%lld\n", maxi);
	cin >> n;
}