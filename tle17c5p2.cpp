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

#define MAXN 100000

int x[MAXN];

int main() {
	int n, d; scan(n); scan(d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	vector<int> fwd;
	vector<int> bk;
	for (int i = 0; i < d; i++) {
		int pi, pj; scan(pi); scan(pj);
		pj--, pi--;
		if (x[pi] < x[pj])
			fwd.push_back(x[pi]),
			fwd.push_back(x[pj]);
		else
			bk.push_back(x[pi]),
			bk.push_back(x[pj]);
	}
	sort(fwd.begin(), fwd.end());
	sort(bk.begin(), bk.end());
	if (fwd.empty())
		printf("%d\n", bk.back() - bk.front());
	else if(bk.empty())
		printf("%d\n", fwd.back() - fwd.front());
	else {
		int bs=(fwd.back()-fwd.front())+abs(fwd.back()-bk.back())+(bk.back()-bk.front());
		bs = min(bs, (bk.back()-bk.front())+abs(bk.front()-fwd.front())+ (fwd.back() - fwd.front()));
		printf("%d\n", bs);
	}
	cin >> n;
}