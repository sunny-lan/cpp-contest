#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string p1 = "What are you doing while sending \"";
string p2 = "\"? Are you busy? Will you send \"";
string p3 = "\"?";

#define MAXN 100010
ll fl[MAXN];

char f(int n, ll k) {
	if (k >= fl[n])
		return'.';

	if (n == 0)return f0[k];

	if (k < p1.length())
		return p1[k];
	k -= p1.length();

	if (k < fl[n - 1])
		return f(n - 1, k);
	k -= fl[n - 1];

	if (k < p2.length())
		return p2[k];
	k -= p2.length();

	if (k < fl[n - 1])
		return f(n - 1, k);
	k -= fl[n - 1];

	if (k < p3.length())
		return p3[k];

	return'.';
}

int main() {
	fl[0] = f0.length();
	for (int i = 1; i < MAXN; i++) {
		fl[i] = p1.length() + p2.length() + p3.length() + 2 * fl[i - 1];
		if (fl[i] > 1ll << 61)
			fl[i] = 1ll << 61;
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int n; ll k; scanf("%d %I64d", &n, &k);
		k--;
		printf("%c", f(n, k));
	}
	cin >> q;
}