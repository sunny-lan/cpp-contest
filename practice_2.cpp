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

#define MAXN 30

int a[MAXN];
bool pred(int a, int b) {
	cout << "? " << (char)('A' + a)<<" " << (char)('A' + b) << endl;
	string res; cin >> res;
	return res == "<";
}

int main() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++)
		a[i] = i;

	sort(a, a + n, pred);

	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << (char)('A' + a[i]);
	cout << endl;
}