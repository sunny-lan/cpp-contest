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
#include <bitset>
#include <stack>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXT 5
#define MAXS 1000

int s, n, t;
int c[MAXT][MAXS];
int ptr[MAXT][MAXS];
int* tmp;
bool pred(int a, int b) {
	return tmp[a] < tmp[b];
}

template<size_t sz>
int f(int i, int cst, bitset<sz> curr) {
	if (i == t) return curr.count() < n ? INT_MAX : cst;
	int res = INT_MAX;
	bitset<sz> curr2;
	for (int j = 0; j < s; j++) {
		int idx = ptr[i][j];
		curr2.set(idx);
		res = min(res, f(i + 1, cst + c[i][idx] * n, curr & curr2));
	}
	return res;
}

bitset<1000> init1;
bitset<30> init2;

int main() {
	scan(s); scan(n); scan(t);
	for (int i = 0; i < s; i++) {
		if (s > 30)init1.set(i);
		else init2.set(i);
		for (int j = 0; j < t; j++) {
			scan(c[j][i]);
			ptr[j][i] = i;
		}
	}

	for (int i = 0; i < t; i++) {
		tmp = c[i], sort(ptr[i], ptr[i] + s, pred);
	}

	if (s > 30) printf("%d\n", f(0, 0, init1));
	else printf("%d\n", f(0, 0, init2));
	cin >> s;
}