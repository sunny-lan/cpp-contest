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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

bool inq[MAXN];

ll *du;
vector<pii> *adj;

void dij(int src) {
	memset(inq, false, sizeof inq);
	du[src] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({ 0,src });
	while (!q.empty()) {
		int curr = q.top().second; q.pop();
		inq[curr] = false;
		for (pii neigh : adj[curr])
		{
			ll alt = neigh.second + du[curr];
			if (alt < du[neigh.first]) {
				du[neigh.first] = alt;
				if (!inq[neigh.first]) {
					q.push({ alt, neigh.first });
					inq[neigh.first] = true;
				}
			}
		}
	}
}

int main() {

}