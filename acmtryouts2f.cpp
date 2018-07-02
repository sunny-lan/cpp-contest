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

//template parameters
#define MAXY 1000010
#define NUM ll

//template begin
NUM bit[MAXY];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x <= MAXY; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main() {
	int t; cin >> t;
	for (int testcase = 0; testcase < t; testcase++) {
		memset(bit, 0, sizeof bit);
		string useless; cin >> useless;
		vector<pair<ll, pii>> vlines;
		vector<pair<ll, int>> starts;
		vector<pair<ll, int>> stops;
		for (int j = 0; j < 2; j++) {
			ll cx; int cy, n;
			cin >> cx >> cy >> n;
			for (int i = 0; i < n; i++) {
				string cmd; ll v; cin >> cmd >> v;
				v--;
				if (cmd == "U") {
					vlines.push_back({ cx,{ cy, cy + v } });
					cy += v+1;
				}
				if (cmd == "D") {
					vlines.push_back({ cx,{ cy - v, cy } });
					cy -= v+1;
				}
				if (cmd == "R") {
					starts.push_back({ cx,cy });
					stops.push_back({ cx + v,cy });
					cx += v+1;
				}
				if (cmd == "L") {
					starts.push_back({ cx - v,cy });
					stops.push_back({ cx ,cy });
					cx -= v+1;
				}
			}
		}
		sort(vlines.begin(), vlines.end());
		sort(starts.begin(), starts.end());
		sort(stops.begin(), stops.end());
		ll cnt = 0;
		int p1 = 0, p2 = 0;
		for (int i = 0; i < vlines.size();i++) {
			ll loc = vlines[i].first;
			int y1 = vlines[i].second.first;
			int y2 = vlines[i].second.second;
			while (p1 < starts.size() && starts[p1].first <= loc)
				update(starts[p1].second, 1), p1++;
			while (p2 < stops.size() && loc > stops[p2].first)
				update(starts[p2].second, -1), p2++;
			cnt += query(y2) - query(y1 - 1);
		}
		cout << cnt  << endl;
	}
	cin >> t;
}