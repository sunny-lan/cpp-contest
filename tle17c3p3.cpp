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

#define MAXN 300001

vector<int> children[MAXN];
int q[MAXN];

ll f(int i) {
	ll maxi = INT_MAX;
	for (int j : children[i])
		maxi = min(maxi, f(j));
	if (maxi >= INT_MAX)
		maxi = 0;
	return maxi + q[i];
}

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int t, k; scan(t); scan(k);
		t--;
		for (int j = 0; j < k; j++) {
			int x; scan(x);
			children[t].push_back(--x);
		}
	}
	for (int i = 0; i < n; i++)
		scan(q[i]);

	printf("%lld\n", f(0));
	cin >> n;
}