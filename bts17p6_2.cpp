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
#define NUM int

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y < MAXN; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int a[MAXN];
int b[MAXN];
unordered_map<int, int> ordA;

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(a[i]);
		ordA[a[i]] = i;
		update(i, 1);
	}
	int prev = -1;
	int bl=0, br=0;
	int l=0, r=0;
	for (int i = 0; i < n; i++) {
		scan(b[i]);
		int k = ordA[b[i]];
		if (k < prev)
			l = i;
		else
			r = i;
		if (r - l > br - bl)
			bl = l, br = r;
		prev = k;
	}
	printf("%d\n", (bl - 1) + (n - br));
	for (int i = bl - 1; i >= 0; i--) {
		int k = ordA[b[i]];
		int mapk = query(k)-1;
		printf("F %d\n", mapk+1);
		update(0, 1);
		update(k, -1);
	}
	for (int i = br + 1; i < n; i++) {
		int k = ordA[b[i]];
		int mapk = query(k )-1;
		printf("B %d\n", mapk+1);
		update(k, -1);
	}
	cin >> n;
}