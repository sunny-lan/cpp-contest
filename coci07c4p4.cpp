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

#define MAXT 5001
#define MAXN 500

bool dp[MAXT];
pii ptr[MAXT];

int cust[MAXN];
int b[MAXN];

int main() {
	memset(cust, -1, sizeof cust);
	memset(ptr, -1, sizeof ptr);

	int t, n; scan(t); scan(n);
	dp[0] = true;
	ptr[0] = { -1, -1 };
	for (int i = 0; i < n; i++) {
		scan(b[i]);
		for (int j = t; j >= b[i]; j--) if (dp[j - b[i]] && !dp[j]) {
			dp[j] = true;
			ptr[j] = { j - b[i], i };
		}
	}

	for (int i = t; i >= 0; i--)if (dp[i]) {
		int tmp = i;
		while (true) {
			pii next = ptr[tmp];
			if (next.first == -1)break;
			cust[next.second] = next.first;
			tmp = next.first;
		}
		break;
	}

	int t2 = 0;
	for (int i = 0; i < n; i++) {
		if (cust[i] == -1) {
			printf("%d ", t2);
			t2 += b[i];
		}
		else printf("%d ", cust[i]);
	}
	printf("\n");

	cin >> n;
}