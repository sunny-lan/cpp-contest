#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

#define MAXN 300010

pii inp[MAXN];

bool pred(pii a, pii b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

pii v[MAXN];
int dp[MAXN][3];
int fuk;
int nxt[MAXN];

// 0=nothing in prev
// 1=prev taken
// 2=prev must be carried

int f(int i, int prev) {
	if (i == fuk )
		if (prev == 2)
			return MAXN;
		else
			return 0;
	int &res = dp[i][prev];
	if (res != -1)return res;
	res = MAXN;
 	if (nxt[i]==-1) {
		if (prev == 0) {
			//cannot be carried by nxt or prev
			res = f(i + 1, 0) + 1;
			cout << "cn";
		}
		else if (prev == 1) {
			//carried already
			res = f(i + 1, 0);
		}
		else if (prev == 2) {
			//must carry
			res = f(i + 1, 0) + 1;
			cout << "mc";
		}
	}
	else {
		if (prev == 2) {
			//must carry prev
			res = min(res, f(nxt[i], 1)+1);
			cout << "p";
		}
		else  if(prev==1){
			//allow prev to carry
			//res = min(res, f(nxt[i]+1, 0));
			res = min(res, f(nxt[i] , 0));
			//carry anyways
			res = min(res, f(nxt[i], 1) + 1);
			cout << "ca";
		}
		else if (prev == 0) {
			//carry by nxt
			res = min(res, f(nxt[i], 2));

			//carry self
			res = min(res, f(nxt[i], 1) + 1);
			cout <<"cs";
			//res = min(res, f(nxt[i]+1, 0)+1);
		}
	}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &inp[i].first, &inp[i].second);

	sort(inp, inp + n, pred);

	//for (int i = 0; i < n; i++) {
	//	printf("[%d, %d)\n", inp[i].second, inp[i].first);
	//}

	set<pii> kusts;
	for (int i = 0; i < n; i++) {
		//printf("[%d, %d)\n", inp[i].second, inp[i].first);
		while (!kusts.empty() && kusts.rbegin()->first >= inp[i].first)
			//printf(" erase [%d, %d)", prev(kusts.end())->second, prev(kusts.end())->first),
			kusts.erase(prev(kusts.end()));
		kusts.insert(inp[i]);
	}

	int idx = 0;
	for (pii x : kusts)
		v[idx++] = x;

	int nidx = 0;
	for (int i = 0; i < idx; i++) {
		nidx = max(i, nidx);

			int tmp=nidx;
			bool flg=false;
			while (tmp+1 < idx && v[tmp+1].first < v[i].second)
				tmp++,flg=true;
			nidx = tmp;
			if (flg)
				nxt[i] = nidx;
			else
				nxt[i] = -1;
		//cout << "nxt " << i << " = " << nxt[i] << endl;
	}

	fuk = idx;

	printf("%d", f(0, 0));

	cin >> fuk;
}