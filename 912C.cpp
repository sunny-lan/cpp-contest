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
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

#define MAXN 100010

ll max_health[MAXN], regen[MAXN];
vector<pll> evt[MAXN];
vector<pli> evt2;

#define INF 9223372036854775807ll

int main() {
	int n, m; scan(n); scan(m);
	ll bounty, increase, damage;
	scan(bounty); scan(increase); scan(damage);
	for (int i = 0; i < n; i++) {
		scan(max_health[i]);
		ll start_health;  scan(start_health);
		scan(regen[i]);
		evt[i].push_back({ 0, start_health });
	}
	for (int i = 0; i < m; i++) {
		ll time, health; int enemy;
		
		scan(time); scan(enemy); scan(health);enemy--;
		evt[enemy].push_back({ time, health });
	}
	for (int i = 0; i < n; i++) {
		sort(evt[i].begin(), evt[i].end());
		for (int j = 0; j < evt[i].size(); j++) {
			ll ed, st = evt[i][j].first,
				new_health = evt[i][j].second;
			if (j == evt[i].size() - 1)
				ed = INF;
			else
				ed = evt[i][j + 1].first;

			if (max_health[i] <= damage)
			{
				evt2.push_back({ st,  1 });
				evt2.push_back({ ed, -1  });
				continue;
			}

			if (new_health > damage)
				continue;

			if (regen[i] == 0)
			{
				evt2.push_back({ st, 1  });
				evt2.push_back({ ed,-1  });
				continue;
			}

			ll nxtCrossing = ((damage - new_health) / regen[i]) + st;

			evt2.push_back({ st, 1  });
			evt2.push_back({ min(nxtCrossing + 1, ed), -1  });
		}
	}

	sort(evt2.begin(), evt2.end());

	int t = 0;
	ll maxi = 0;
	//ll lastevt = -INF;
	for (int i = 0; i < evt2.size();) {
		auto e = evt2[i];
		ll time = e.first;
		if (time != 0) {
			ll alt;
			if (time == INF && increase!=0)
				alt = INF;
			else 
				alt = t*(bounty + (time-1)*increase);
			maxi = max(maxi, alt);
		}
		while (i<evt2.size() && evt2[i].first == time)
			t += evt2[i].second, i++;
		ll alt;
		if (time == INF  && increase != 0)
			alt = INF;
		else
			alt = t*(bounty + time*increase);
		maxi = max(maxi, alt);
		//lastevt = time;
	}
	if (maxi == INF)
		maxi = -1;
	printf("%I64d\n", maxi);
	
}