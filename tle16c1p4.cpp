#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF(a) (a==-1?INT_MAX:a)

#define MAXN 100

int m[MAXN];
int _du[MAXN][MAXN];
bool _v[MAXN][MAXN];

vector<pair<int, int>> adj[MAXN];

bool can[MAXN][MAXN];

int main() {
	memset(_du, -1, sizeof _du);

	int n, e, k; scan(n); scan(e); scan(k);
	for (int i = 0; i < n; i++)
		scan(m[i]);

	for (int i = 0; i < e; i++) {
		int u, v, d; scan(u); scan(v); scan(d);
		u--, v--;
		adj[u].push_back({ v, d });
		adj[v].push_back({ u, d });
	}

	for (int node = 0; node < n; node++) {
		int *du = _du[node];
		bool *v = _v[node];
		du[node] = 0;
		while (true) {
			int mini = -1;
			int i = -1;
			for (int j = 0; j < n; j++)
			{
				if (v[j])continue;
				if (INF(du[j]) < INF(mini)) {
					mini = du[j];
					i = j;
				}
			}

			if (i == -1)
				break;

			if (mini <= k)
				can[node][i] = true;

			for (auto j : adj[i]) {
				du[j.first] = min(INF(du[j.first]), mini + j.second);
			}
			v[i] = true;
		}
	}

	int maxi = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
			{
				int tot = 0;
				for (int l = 0; l < n; l++)
					if (can[i][l] || can[j][l] || can[k][l])
						tot += m[l];
				maxi = max(maxi, tot);
			}

	cout << maxi << endl;
	cin >> n;
}