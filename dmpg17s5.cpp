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

int incr(int i) {
	if (i == 0)return 1;
	if (i == 1)return 3;
	if (i == 3)return 2;
	if (i == 2)return 0;
}

int curr = 0;
int idx = 0;
int nums[1030];
void f(int i) {
	if (i < 0) {
		nums[idx++] = curr;
		return;
	}
	int d = (curr >> i) & 3,
		k=d;
	for (int j = 0; j < 4; j++) {
		curr &= ~(3 << i);
		curr |= k << i;
		f(i - 2);
		if (idx >= 1024)return;
		k = incr(k);
	}
}

int main() {
	f(10);
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", (nums[i] << 10) | (nums[j]));
		}
		printf("\n");
	}
	cin >> n;
}