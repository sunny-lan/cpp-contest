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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 20000

vector<int> children[MAXN];

int ans=-1;

int l[MAXN];

int f(int i) {
	int maxi = -1;
	int maxi2 = -1;
	for (int child : children[i]) {
		int res = f(child);
		if (res > maxi)
		{
			maxi2 = maxi;
			maxi = res;
		}
		else if (res > maxi2) {
			maxi2 = res;
		}
	}
	ans = max(ans, maxi2);
	return max(maxi, l[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int p; cin >> p; p--;
		children[p].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		l[i] = s.length();
	}
	f(0);
	printf("%d\n", ans);
	cin >> n;
}