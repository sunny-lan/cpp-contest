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

#define NUM ll
//finds gcd of two numbers
inline NUM gcd(const NUM &a, const NUM &b) {
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> adj[MAXN];

int x[MAXN];
ll num[MAXN];
ll den[MAXN];

ll mn = 1, md = 0;

ll on[MAXN], od[MAXN], b2n[MAXN], b2d[MAXN];

ll q, aln, an, ad, r, ald;

void f(int i, int j) {
	num[i] = 1, den[i] = 0;
	b2n[i] = 1, b2d[i] = 0;
	on[i] = x[i], od[i] = 1;
	for (int tmp = 0; tmp < adj[i].size(); tmp++) {
		int neigh = adj[i][tmp];
		if (neigh != j) {
			f(neigh, i);
			q = num[neigh] * den[i],
				r = num[i] * den[neigh];
			if (q < r) {
				b2n[i] = num[i], b2d[i] = den[i];
				num[i] = num[neigh], den[i] = den[neigh];
			}
			else if (q == r)
				b2n[i] = num[neigh], b2d[i] = den[neigh];

			aln = x[i] * num[neigh], ald = den[neigh] + 1;
			if (aln * od[i] < on[i] * ald)
				on[i] = aln, od[i] = ald;
		}
	}
	an = num[i] * b2n[i] * x[i],
		ad = den[i] + b2d[i] + 1;
	if (an * md < mn * ad)
		mn = an, md = ad;
	if (on[i] * md < mn * od[i])
		mn = on[i], md = od[i];
	num[i] = on[i], den[i] = od[i];
}

int main() {
	   freopen("C:\\Users\\Sunny\\Downloads\\contest1_testdata\\mag\\mag.in.4a", "r", stdin);

	int n;
	scan(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scan(a);
		scan(b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		scan(x[i]);

	f(0, -1);

	ll k = gcd(mn, md);
	printf("%lld/%lld\n", mn / k, md / k);
	cin >> k;
}