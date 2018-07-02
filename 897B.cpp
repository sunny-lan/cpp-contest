#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	int k;ll p; scanf("%d %I64d", &k, &p);
	ll sum = 0;
	for (int i = 1; i <= k; i++) {
		string s = to_string(i);
		string b = s;
		reverse(s.begin(), s.end());
		b += s;
		ll num = atoll(b.c_str());
		sum += num;
		sum %= p;
	}
	printf("%I64d\n", sum);
	cin >> k;
}