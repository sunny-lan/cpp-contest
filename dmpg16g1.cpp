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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MOD 1000000007
priority_queue<int, vector<int>, greater<int>> q;
int main() {
	int n; scan(n);
	int cnt = 0;
	ll lo = 0;
	for (int i = 0; i < n; i++)
	{
		int p; scan(p);
		if (p == 1)cnt++;
		else lo+=p, q.push(p), lo %= MOD;
	}

	if (cnt == n)lo = 1;

	while (!q.empty() && cnt > 0)
		if (q.top() == 2)q.push(3), cnt--, q.pop();
		else
			break;

	while (cnt >= 3)
		cnt -= 3, q.push(3);

	while (cnt >= 2)
		cnt -= 2, q.push(2);

	while (!q.empty() && cnt > 0)
		cnt--, q.push(q.top() + 1), q.pop();

	ll hi = 1;
	while (!q.empty())hi *= q.top(), q.pop(), hi %= MOD;

	printf("%lld\n%lld\n", lo, hi);
	cin >> cnt;
}