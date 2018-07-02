#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int adj[110][110];

int getDistance(int i, int j) {
	return adj[i][j];
}

#define MAXN 110

int da[MAXN], du[MAXN];
int mini;
bool balanced(int N, int cd) {
	vector<pii> cur;
	int l = 0, r = 0;
	for(int i = 0; i < N; i++) {
		int k = ((du[0] - cd) + (du[i] - cd) - da[i]) / 2;
		if(k < 0)
			l++;
		else if(k > 0)
			r++;
		else
			cur.push_back({i, 1});
	}

	if(l > N / 2 || r > N / 2)
		return false;

	while(cur.size() > 1) {
		vector<pii> nxt;
		for(int i = 0; i + 1 < cur.size(); i += 2)
		{
			int ad = getDistance(cur[i].f, cur[i + 1].f),
				gd = (du[cur[i].f] + du[cur[i + 1].f] - 2 * cd);
			if(gd != ad)
				nxt.push_back({cur[i].first, cur[i].second + cur[i + 1].second});
		}
		if(cur.size() % 2 == 1)
			nxt.push_back(cur.back());
		cur = nxt;
	}

	if(cur.size() == 1)
		return false;

	return true;
}

int hubDistance(int N, int sub) {
	int u, v, maxi = -1;
	for(int i = 1; i < N; i++) {
		da[i] = getDistance(i, 0);
		if(da[i] > maxi)
			maxi = da[i], u = i;
	}

	maxi = -1;
	for(int i = 0; i < N; i++)
	{
		du[i] = getDistance(i, u);
		if(du[i] > maxi)
			maxi = du[i], v = i;
	}

//	int jp = (du[0]+maxi-da[v])/2;

	mini = INT_MAX;
	vector<int> ksut;
	for(int i = 0; i < N; i++) {
		int dd = (du[0] + du[i] - da[i]) / 2;
//            if(dd>jp)continue;
		int alt = max(dd, maxi - dd);
		if(alt < mini)
			mini = alt, ksut.clear();
		if(mini == alt)
			ksut.push_back(dd);
	}

	for(int i : ksut)
		if(balanced(N, i))
			return -mini;

	return mini;
}

int main() {
	freopen("C:\\Users\\Sunny\\Downloads\\towns\\towns\\tests\\subtask_1\\01", "r", stdin);

	int sub, t;
	scanf("%d %d", &sub, &t);
	for(int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &adj[i][j]);
		printf("%d\n", hubDistance(n, sub));
	}
}
