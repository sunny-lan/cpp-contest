#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

bool del[MAXN];
int cnt[MAXN][3];
vector<int> rws[MAXN];
int v[MAXN][3];
bool inq[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i][j]),
			v[i][j]--,
				  cnt[v[i][j]][j]++,
				  rws[v[i][j]].push_back(i);
	}
	queue<int> col;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
			if(cnt[i][j] == 0) {
				col.push(i);
				inq[i]=true;
				break;
			}

	int res = 0;
	while(!col.empty()) {
		int nxt = col.front();
		col.pop();
		for(int r : rws[nxt])
			if(!del[r]) {
				for(int j = 0; j < 3; j++)
                    if(!inq[v[r][j]])
					if(--cnt[v[r][j]][j] <= 0)
						col.push(v[r][j]),inq[v[r][j]]=true;
				res++;
				del[r] = true;
			}
	}

	printf("%d\n", res);
}
