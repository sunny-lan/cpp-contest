#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <functional>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 101

string map[MAXN];

int du[MAXN][MAXN];
bool inq[MAXN][MAXN];
bool cam[MAXN][MAXN];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;

void ad(int lvl, int r, int c) {
	if (lvl < du[r][c])
	{
		du[r][c] = lvl;
		if (!inq[r][c]) {
			q.push({ lvl,{r,c} });
			inq[r][c] = true;
		}
	}
}

int main() {
	memset(du, 0x3f, sizeof du);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	int bx, by;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'S')
				bx = i, by = j, map[i][j]='.';
		}
	}
	for (int i = 0; i < n; i++)
		for(int j=0;j<m;j++)
			if (map[i][j] == 'C') {
				for (int u = i; u >=0; u--) {
					if (map[u][j] == 'W')break;
					if(map[u][j]=='.')
					cam[u][j] = true;
				}
				for (int u = i; u <n; u++) {
					if (map[u][j] == 'W')break;
					if (map[u][j] == '.')
						cam[u][j] = true;
				}
				for (int u = j; u >= 0; u--) {
					if (map[i][u] == 'W')break;
					if (map[i][u] == '.')
						cam[i][u] = true;
				}
				for (int u = j; u <m; u++) {
					if (map[i][u] == 'W')break;
					if (map[i][u] == '.')
						cam[i][u] = true;
				}
			}
	q.push({0, {bx,by} });
	du[bx][by] = 0;
	inq[bx][by] = true;
	while (!q.empty()) {
		pii cur = q.top().second; q.pop();
		int r = cur.first,  c= cur.second;
		inq[r][c] = false;
		if (map[r][c] == 'W')continue;
		if (cam[r][c]) { du[r][c] = INT_MAX; continue; }
		int lvl = du[r][c];
		if (map[r][c] == 'L') {
			ad( lvl, r, c - 1 );
		}
		if (map[r][c] == 'R')
			ad(lvl, r, c + 1  );
		if (map[r][c] == 'U')
			ad(lvl, r - 1, c );
		if (map[r][c] == 'D')
			ad(lvl, r + 1, c );
		if (map[r][c] == '.') {
			ad(lvl+1, r, c - 1 );
			ad(lvl+1,r, c + 1 );
			ad(lvl+1,r - 1, c );
			ad(lvl+1, r + 1, c );
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == bx&&j == by)continue;
			if (du[i][j] >= 0x3f3f3f3f)
				du[i][j] = -1;
			if (map[i][j] == '.')
				printf("%d\n", du[i][j]);
		}
	cin >> n;
}