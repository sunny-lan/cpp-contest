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

#define MAXN 3001
#define ENDT 80000000
#define INF 1<<30
#define INFP { INF,INF }

int j, w, l;
int a[MAXN * 2];
int b[MAXN * 2];
int ptr[MAXN * 2];
bool pred(int x, int y) {
	return a[x] < a[y];
}

unordered_map<int, pii> dp[MAXN * 2];

pii f(int i, int k, bool c) {
	if (k + l > ENDT)return{ 0,0 };
	if (i == j + w)return INFP;
	if (a[ptr[i]] >= k + l)return INFP;
	if (dp[i].find(k) != dp[i].end())
		return dp[i][k];

	pii alt1 = f(i + 1, k, true);

	pii alt2 = INFP;
	if (a[ptr[i]] >= k || c) {
		alt2 = f(i + 1, b[ptr[i]], a[ptr[i]] >= k);
		if (ptr[i] < j) alt2.first++;
		else alt2.second++;
	}

	return dp[i][k] = max(alt1.first, alt1.second) < max(alt2.first, alt2.second) ? alt1 : alt2;;
}

int main() {
	int T; scan(T);
	for (int test = 1; test <= T; test++) {
		scan(j); scan(w); scan(l);
		for (int i = 0; i < j; i++) {
			scan(a[i]); scan(b[i]);
			dp[i].clear();
			ptr[i] = i;
		}
		for (int i = j; i < j + w; i++) {
			scan(a[i]); scan(b[i]);
			dp[i].clear();
			ptr[i] = i;
		}
		sort(ptr, ptr + j + w, pred);
		pii res = f(0, 0, true);
		int out = max(res.first, res.second);
		printf("Case #%d: ", test);
		if (out < INF)
			printf("%d\n", out);
		else printf("Lunchtime\n");
	}
	cin >> T;

}