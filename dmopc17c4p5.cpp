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

#define MAXN 1000001

bool ans[4][MAXN];

int cnt[16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < 4; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == 'T')
				ans[i][j] = true;
			else
				ans[i][j] = false;
	}
	for (int i = 0; i < n; i++) {
		int kust = 0;
		for (int j = 0; j < 4; j++) {
			if (ans[j][i])
				kust |= 1 << j;
		}
		cnt[kust]++;
	}
	ll maxi = 0; int best;
	for (int cmb = 0; cmb < 1 << 16; cmb++) {
		ll kust[] = { 0,0,0,0 };
		for (int i = 0; i < 16; i++) {
			if ((cmb >> i) & 1)//true
			{
				for (int j = 0; j < 4; j++) {
					if ((i >> j) & 1) {
						kust[j] += cnt[i];
					}
					else {
						kust[j] -= cnt[i];
					}
				}
			}
			else {//false
				for (int j = 0; j < 4; j++) {
					if ((i >> j) & 1) {
						kust[j] -= cnt[i];
					}
					else {
						kust[j] += cnt[i];
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += kust[i] * kust[i];
		}
		if (ans>maxi) {
			maxi = ans;
			best = cmb;
		}
	}

	for (int i = 0; i < n; i++) {
		int kust = 0;
		for (int j = 0; j < 4; j++) {
			if (ans[j][i])
				kust |= 1 << j;
		}
		if ((best >> kust) & 1)
			printf("T");
		else
			printf("F");
	}
	cin >> n;
}