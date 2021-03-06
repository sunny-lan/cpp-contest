#ifndef _MSC_VER

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
typedef pair<ll, ll> pll;

#define f first
#define s second

ll fib[1000];
pll dir[] = { { -1,-1 },{ -1,1 },{ 1,1 },{ 1,-1 } };

bool between(ll a, ll b, ll c) {
	return min(a, b) <= c && c <= max(a, b);
}

bool inside(pll a, pll b, ll x, ll y) {
	return between(a.f, b.f, x) && between(a.s, b.s, y);
}

int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\SAMPLE4.txt", "r", stdin);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i<1000; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	for (int testcase = 0; testcase < 10; testcase++) {
		ll px, py;
		cin >> px >> py;
		ll prevX = 1, prevY = 0;
		ll x, y;
		for (int i = 0; i<1000; i++) {
			x = prevX + dir[i % 4].f*fib[i];
			y = prevY + dir[i % 4].s*fib[i];
			if (inside({ prevX,prevY }, { x,y }, px, py)) {
				cout << i + 1 << endl;
				break;
			}
			prevX = x;
			prevY = y;
		}
	}

}
