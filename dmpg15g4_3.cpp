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
typedef pair<double, double> pdd;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//template parameters
#define MAXN 400010
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

unordered_map<double, int > ord;

int main() {
	int n; double xe; scanf("%d %lf", &n, &xe);
	vector<pdd> custs;
	vector<double> morecust;
	for (int i = 0; i < n; i++) {
		double x, y; scanf("%lf %lf", &x, &y);
		double a = atan(y / x);
		double b = atan(y / (xe - x));
		custs.push_back({ a, b });
		morecust.push_back(b);
	}
	sort(custs.begin(), custs.end());
	sort(morecust.begin(), morecust.end());
	for (int i = 0; i < n; i++)
		ord[morecust[i]] = i;

	ll dis = 0;
	int tot = 0;
	for (int i = n - 1; i >= 0; i--) {
		int r = ord[custs[i].second];
		ll c = tot - query(r-1);
		dis += c*c;
		tot++;
		update(r, 1);
	}

	printf("%lld\n", dis);

	cin >> n;
}