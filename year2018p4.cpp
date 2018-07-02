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

#define MAXS 200
#define MAXD 20

bool visited[MAXD][MAXS][2][2];
bool other[MAXS];

string l, r;

int cnt = 0;
void f(int d, int s, int pl, int ph) {
	if (d == -1) {
		if (other[s])return;
		other[s] = true;
		cnt++;
	}
	else {
		if (visited[d][s][pl][ph])
			return;
		visited[d][s][pl][ph] = true;
		int hi = 9;
		int lo = 0;
		if (pl == 1)
			lo = l[d] - '0';
		if (ph == 1)
			hi = r[d] - '0';
		for (int i = lo; i <= hi; i++) 
			f(d - 1, s + i, pl & (i == lo), ph &(i == hi));
	}
}

int main() {
	cin >> l >> r;
	reverse(l.begin(), l.end());
	reverse(r.begin(), r.end());
	l += "000000000000000000000000";
	r += "000000000000000000000000";
	f(MAXD - 1, 0, 1, 1);
	printf("%d\n", cnt);
}