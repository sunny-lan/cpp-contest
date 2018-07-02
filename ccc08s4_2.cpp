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

int apply(int i, int j, int op) {
	if (op == 0)
		return i + j;
	if (op == 1) {
		return i - j;
	}
	if (op == 2)
		return i*j;
	if (op == 3) {
		if (j == 0)return -1;
		if (i%j == 0)return i / j;
		return -1;
	}
	return -999999;
}

int maxi;
void f(vector<int> st) {
	if (st.size() == 1) {
		if (st[0] > 24)return;
		maxi = max(maxi, st[0]);
		return;
	}
	for (int a = 0; a < st.size(); a++)
		for (int b = 0; b < st.size(); b++)
			if (a != b)
				for (int o = 0; o < 4; o++) {
					int alt = apply(st[a], st[b], o);
					if (alt == -1)continue;
					vector<int> nxt;
					for (int i = 0; i < st.size(); i++)
						if (i != a && i != b)
							nxt.push_back(st[i]);
					nxt.push_back(alt);
					f(nxt);
				}
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		vector<int> nms;
		for (int j = 0; j < 4; j++) {
			int a; scan(a);
			nms.push_back(a);
		}
		maxi = -1;
		f(nms);
		printf("%d\n", maxi);

	}cin >> n;
}