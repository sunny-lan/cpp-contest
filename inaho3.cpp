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
#include <functional>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define MAXN 12
#define MAXP 2000001

int n;
int l[MAXN];
int base[MAXN];

ll d[MAXP];

bool inq[MAXP];

ll du[MAXP];
int ptr[MAXP];

void dij(int src) {
	memset(du, 0x3f, sizeof du);
	memset(inq, false, sizeof inq);
	du[src] = d[src];
	ptr[src] = -1;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({ d[src],src });
	while (!q.empty()) {
		int curr = q.top().second; q.pop();
		inq[curr] = false;
		int di = 1;
		for (int i = 0; i < n; i++)
		{
			int dim = l[i] * di;
			{
				int j = curr + di;
				if (j < base[n] && j / dim == curr / dim) {
					ll alt = d[j] + du[curr];
					if (alt < du[j]) {
						du[j] = alt;
						ptr[j] = curr;
						if (!inq[j]) {
							q.push({ alt, j });
							inq[j] = true;
						}
					}
				}
			}
			{
				int j = curr - di;
				if (j >= 0 && j / dim == curr / dim) {
					ll alt = d[j] + du[curr];
					if (alt < du[j]) {
						du[j] = alt;
						ptr[j] = curr;
						if (!inq[j]) {
							q.push({ alt, j });
							inq[j] = true;
						}
					}
				}
			}
			di = dim;
		}
	}
}


int main() {
	scan(n);
	base[0] = 1;
	for (int i = 0; i < n; i++) {
		scan(l[i]);
		base[i + 1] = base[i] * l[i];
	}

	int src, dst;
	ll maxi = -1, mini = 1ll << 40;

	for (int i = 0; i < base[n]; i++) {
		scan(d[i]);
		if (d[i] >= maxi)
			maxi = d[i],
			src = i;
		if (d[i] < mini)
			mini = d[i],
			dst = i;
	}

	dij(src);

	printf("%lld\n", du[dst]);

	vector<string> out;

	int curr = dst;
	while (curr != -1) {
		string res = "";
		cout << curr << endl;
		for (int i = 0; i < n; i++)
			res += to_string(curr / base[i] % l[i]) + " ";
		out.push_back(res);
		curr = ptr[curr];
	}

	for (int i = out.size() - 1; i >= 0; i--)
		printf("%s\n", out[i].c_str());

	cin >> n;
}