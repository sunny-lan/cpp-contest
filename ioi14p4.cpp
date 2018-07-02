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

#define MAXN 100000
#define MOD 1000000009

unordered_map<int, int> cnt;

int off;
bool hasoff;
void goff(int n, int inputSeq[]) {
	off = 0, hasoff = false;
	for (int i = 0; i < n; i++)
		if (inputSeq[i] <= n) {
			off = i + 1 - inputSeq[i];
			hasoff = true;
			break;
		}
	off += n, off %= n;
}

int valid(int n, int inputSeq[]) {
	cnt = unordered_map<int, int>();
	goff(n, inputSeq);

	for (int i = 0; i < n; i++) {
		int idx = (i + off) % n,
			num = inputSeq[idx];
		if (++cnt[num] > 1)return 0;
		if (num <= n)
			if (num != i + 1)return 0;
	}
	return 1;
}

vector<pii> custs;
void gcusts(int n, int gondolaSeq[]) {
	custs = vector<pii>();
	for (int i = 0; i < n; i++)
		if (gondolaSeq[i] > n)
			custs.push_back({ gondolaSeq[i],i });

	sort(custs.begin(), custs.end());
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
	gcusts(n, gondolaSeq);
	goff(n, gondolaSeq);
	for (int i = 0; i < n; i++)
		gondolaSeq[(i + off) % n] = i + 1;

	int i = 0;
	for (pii cust : custs)
		while (i + n != cust.first) {
			replacementSeq[i] = gondolaSeq[cust.second];
			i++;
			gondolaSeq[cust.second] = i + n;
		}
	return i;
}

ll fastpow(int a, int p) {
	ll curr = a;
	ll res = 1;
	while (p > 0) {
		if (p & 1)
			res *= curr, res %= MOD;
		curr *= curr, curr %= MOD;
		p >>= 1;
	}
	return res;
}

int countReplacement(int n, int inputSeq[]) {
	if (!valid(n, inputSeq))return 0;
	gcusts(n, inputSeq);
	int curr = n + 1;
	int avail = custs.size();
	ll res = 1;
	for (pii cust : custs) {
		int val = cust.first;
		res *= fastpow(avail, val - curr), res %= MOD;
		curr = val + 1;
		avail--;
	}
	if (!hasoff)res *= n, res %= MOD;
	return (int)res;
}