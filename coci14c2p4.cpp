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
#include <stack>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000

int a[MAXN][MAXN];
int hor[MAXN][MAXN];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scan(a[i][j]);
			hor[i][j] = 1;
			if (j > 0 && a[i][j - 1] == a[i][j])
				hor[i][j] += hor[i][j - 1];
		}
	}

	ll tot = 0;
	for (int j = 0; j < m; j++) {
		stack<pair<pii,ll>> cust;
		for (int i = 0; i < n; i++) {
			if (i==0 || a[i][j] != a[i - 1][j])
				cust = stack<pair<pii, ll>>(),
				cust.push({ {0, i-1},0 });
			int lst = i;
			while (cust.top().first.first > hor[i][j]) {
				lst = cust.top().first.second;
				cust.pop();
			}
			ll curr = (i - lst)*hor[i][j] + cust.top().second + hor[i][j];
			tot += curr;
			cust.push({ { hor[i][j], lst }, curr });
		}
	}
	printf("%lld\n", tot);
	cin >> tot;
}