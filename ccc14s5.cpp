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

#define MAXN 2010

int x[MAXN];
int y[MAXN];

int dp[MAXN];
int cp[MAXN];
int dist[MAXN];

int main() {
	int n; scan(n);
	n++;
	for (int i = 1; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	vector<pair<int, pii>> custs;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j],
				dy = y[i] - y[j];
			custs.push_back({ dx*dx + dy*dy, {i,j} });
		}

	sort(custs.begin(), custs.end());

	for (auto cust : custs) {
		int d = cust.first,
			a = cust.second.first,
			b = cust.second.second;

		if (d != dist[a]) {
			dist[a] = d;
			cp[a] = dp[a];
		}
		if (d != dist[b]) {
			dist[b] = d;
			cp[b] = dp[b];
		}

		if (a == 0)
			dp[a] = max(dp[a], cp[b]);
		else
		{
			dp[a] = max(dp[a], cp[b] + 1);
			dp[b] = max(dp[b], cp[a] + 1);
		}
	}

	cout << dp[0] + 1 << endl;
}