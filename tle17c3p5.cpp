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

#define MAXN 10
#define MAXT 60000
int n;
int tot = 1;
int a[MAXN];
int base[MAXN];
ll x[MAXT];
ll ans;

bool visited[MAXT];

void f(int idx, int num) {
	if (idx == n) {
		if (visited[num])return;
		ans += x[num];
		visited[num] = true;
		return;
	}
	int digit = num / base[idx] % a[idx];
	if (digit > 0)
		f(idx + 1, num - base[idx]);
	if (digit < a[idx] - 1)
		f(idx + 1, num + base[idx]);
	f(idx + 1, num);
}

int main() {
	scan(n);
	base[0] = 1;
	for (int i = n-1; i >=0; i--) {
		scan(a[i]);
		tot *= a[i];
	}

	for(int i=0;i<n;i++)
		base[i + 1] = base[i] * a[i];

	for (int i = 0; i <tot; i++)
		scan(x[i]);

	//for (int i = 0; i < tot; i++) {
	//	cout << " " << i << " - ";
	//	for (int j = 0; j < n; j++) {
	//		int digit = i / base[j] % a[j];
	//		cout << digit + 1;
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < tot; i++) {
		memset(visited, false, sizeof visited);
		visited[i] = true;
		ans = 0;
		f(0, i);
		printf("%lld\n", ans);
	}
	cin >> n;
}