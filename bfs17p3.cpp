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
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 3000

vector<int> adj[MAXN];

pair< pii, int> loc[MAXN];


bool visited[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	int baller1;
	int init1=-1;
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		int x, y, r; scan(x); scan(y); scan(r);
		loc[i] = { { x,y } , r };
		if (r == 9001)
			baller1 = i;
		if (y > maxi) {
			maxi = y;
			init1 = i;
		}
	}


	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			auto l1 = loc[i];
			auto l2 = loc[j];
			int dx = abs(l1.first.first - l2.first.first);
			int dy = abs(l1.first.second - l2.first.second);
			int dist = dx*dx + dy*dy;
			if (dist <= l1.second*l1.second)
				adj[i].push_back(j);
			if (dist <= l2.second* l2.second)
				adj[j].push_back(i);
		}




	int dist1 = INT_MAX;

	queue<pii> q;
	q.push({ init1 ,0 });
	while (!q.empty()) {
		pii curr = q.front(); q.pop();
		int i = curr.first;
		int d = curr.second;
		if (visited[i])continue;
		visited[i] = true;
		if (i == baller1) {
			dist1 = d;
			break;
		}
		for (int neigh : adj[i]) {
			q.push({ neigh ,d + 1 });
		}
	}while (!q.empty())q.pop();
	for (int i = 0; i < n; i++)
		adj[i].clear();

	int baller2;
	int init2 = -1;
	maxi = -1;
	for (int i = 0; i < m; i++) {
		int x, y, r; scan(x); scan(y); scan(r);
		loc[i] = { { x,y } , r };
		if (r == 9001)
			baller2 = i;
		if (y > maxi) {
			maxi = y;
			init2 = i;
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			auto l1 = loc[i];
			auto l2 = loc[j];
			int dx = abs(l1.first.first - l2.first.first);
			int dy = abs(l1.first.second - l2.first.second);
			int dist = dx*dx + dy*dy;
			if (dist <= l1.second*l1.second)
				adj[i].push_back(j);
			if (dist <= l2.second* l2.second)
				adj[j].push_back(i);
		}

	int dist2 = INT_MAX;

	queue<pii> q2;
	q2.push({  init2 ,0 });
	memeset(visited, false, sizeof visited);
	while (!q2.empty()) {
		pii curr = q2.front(); q2.pop();
		int i = curr.first;
		int d = curr.second;
		if (visited[i])continue;
		visited[i] = true;
		if (i == baller2) {
			dist2 = d;
			break;
		}
		for (int neigh : adj[i]) {
			q2.push({ neigh ,d + 1 });
		}
	}

	if (dist1 < dist2)
		cout << "We are the champions!" << endl;
	else if (dist2<dist1)
		cout << ":'(" << endl;
	else
		cout << "SUDDEN DEATH" << endl;
}