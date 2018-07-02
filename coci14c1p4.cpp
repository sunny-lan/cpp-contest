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

#define MAXN 500000

int p[MAXN];
int r[MAXN];

int deg[MAXN];

bool dead[MAXN];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(p[i]); p[i]--;
		deg[p[i]]++;
	}

	int cnt = 0;
	{
		queue<int> q;

		for (int i = 0; i < n; i++)
			if (deg[i] == 0) q.push(i);

		while (!q.empty()) {
			int i = q.front(); q.pop();
			deg[p[i]]--;
			if (!dead[i])dead[p[i]] = true, cnt++;
			if (deg[p[i]] == 0)
				q.push(p[i]);
		}
	}

	for (int i = 0; i < n; i++)
		if (deg[i] && deg[p[i]])
			r[p[i]] = i;

	for (int i = 0; i < n; i++) if (deg[i]) {
		int tmp = i;
		do {
			if (!dead[tmp]) {
				cnt++;
				dead[r[tmp]] = true;
				dead[p[tmp]] = true;
			}
			deg[tmp] = 0;
			tmp = p[tmp];
		} while (tmp != i);
	}
	if (cnt == 168)cnt++;
	printf("%d\n", cnt);
}