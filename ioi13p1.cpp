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

#define MAXN 100000

vector<pii> adj[MAXN];
bool visited[MAXN];

int dA[MAXN];
int dB[MAXN];


int* tmp;//current array to fill with distances
int tmp2[MAXN];

int src[MAXN];

//returns furthest node, dist is stored in currArr
int dfs(int i, int j, int lvl) {
	tmp[i] = lvl;
	int ret = i;
	int max = lvl;
	visited[i] = true;
	src[i] = j;
	for (auto neigh : adj[i]) {
		if (neigh.first != j) {
			int alt = dfs(neigh.first, i, lvl + neigh.second);
			if (tmp[alt] > max) {
				max = tmp[alt];
				ret = alt;
			}
		}
	}
	tmp2[i] = max;
	return ret;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for (int i = 0; i < M; i++) {
		adj[A[i]].push_back({ B[i] , T[i] });
		adj[B[i] ].push_back({ A[i], T[i] });
	}


	int maxi = -1;
	int b1;

	vector<int> stuff;

	for (int i = 0; i < N; i++) if (!visited[i]) {
		tmp = dA;
		int u = dfs(i, -1, 0);
		int v = dfs(u, -1, 0);
		tmp = dB;
		u = dfs(v, -1, 0);

		int totd = dB[u];

		int mini = INT_MAX;
		int best;

		int ptr = u;
		while (ptr != -1) {
			int a = dB[ptr],
				b = totd - a,
				alt = max(a, b);
			if (alt < mini) {
				mini = alt;
				best = ptr;
			}
			ptr = src[ptr];
		}

		stuff.push_back(best);

		if (mini > maxi) {
			b1 = best;
			maxi = mini;
		}
	}

	for (int b : stuff)if (b != b1) {
		adj[b1].push_back({ b , L });
		adj[b].push_back({ b1, L });
	}

	memset(dA, 0, sizeof dA);
	memset(dB, 0, sizeof dB);
	tmp = dA;
	int u = dfs(0, -1, 0);
	int v = dfs(u, -1, 0);
	tmp = dB;
	u = dfs(v, -1, 0);
	return dB[u];
}

int a[] = { 0,8,2,5,5,1,1,10 };
int b[] = { 8,2,7,11,1,3,9,6 };
int t[] = { 4,2,4,3,7,1,5,3 };
int main() {
	cout << travelTime(12, 8, 2, a, b, t) << endl;
	int tmp;
	cin >> tmp;
}