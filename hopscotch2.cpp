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

#define MAXN 16777300

int ptr[MAXN];
ll dp[MAXN];

int main() {
	int n, k; scan(n); scan(k);
	//queue is sorted from min to max, and in order of indexes
	//anything at front of queue that is out of sliding window is poped
	//whenever a new element is added to the sliding window, 
	//the back of queue is popped until it is < than the new elem
	deque<pair<int, ll>> q;
	q.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		ll x; scan(x);
		while (q.front().first < i - k)
			q.pop_front();
		dp[i] = q.front().second + x;
		ptr[i] = q.front().first;
		while (!q.empty() && q.back().second >= dp[i])
			q.pop_back();
		q.push_back({ i, dp[i] });
	}
	ll mini = LLONG_MAX;
	int best;
	for (int i = n - k + 1; i <= n; i++)
		if (dp[i] <= mini)
			best = i, mini = dp[i];

	vector<int> out;
	while (best != 0)
		out.push_back(best),
		best = ptr[best];

	printf("%lld\n", mini);
	for (int i = out.size() - 1; i >= 0; i--)
		printf("%lld ", out[i]);
	printf("\n");
}