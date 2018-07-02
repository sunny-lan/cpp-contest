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

#define MAXN 1000000

int p[MAXN];
int s[MAXN];
bool c[MAXN];
bool visited[MAXN];

int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	int px = find(x),
		py = find(y);

	if (px == py) {
		c[px] = true;
		return;
	}

	s[px] += s[py];
	p[py] = px;
	s[py] = 0;
}

int main() {
	int n, m, k; scan(n); scan(m); scan(k);

	for (int i = 0; i < n; i++) {
		p[i] = i;
		s[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		merge(a, b);
	}

	int cut = 0;
	int f = 0;

	for (int i = 0; i < n; i++) {
		int pi = find(i);
		if (visited[pi])continue;
		visited[pi] = true;
		int size = s[pi];
		if (size == 0)continue;
		int num= (size / k)*k;
		if (num == 0)continue;
		f += num;
		if (c[pi]) {
			if (s[pi] == k) 
				continue;
			cut++;
		}

		if (size%k != 0)
			cut++;

		cut += size / k - 1;
	}

	printf("%d %d\n", f, cut);
	cin >> n;
}