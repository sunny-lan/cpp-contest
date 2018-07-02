#include <bits/stdc++.h>
using namespace std;

#define MAXN 510

int n, m, k;
int best[MAXN][MAXN];

int dp[MAXN][MAXN];

int f(int i, int j) {
	if(i == n)
		return 0;
	int &res = dp[i][j];
	if(res != -1)
		return res;
	res = n * m;
	for(int l = 0; l <= j; l++)
		res = min(res, best[i][l] + f(i + 1, j - l));
	return res;
}

int main() {
	memset(best, 0x3f, sizeof best);
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
//		cout << "i=" << i << endl;
		string c;
		cin >> c;
		vector<int> kust;
		for(int j = 0; j < m; j++)
			if(c[j] == '1')
				kust.push_back(j);
//		cout << " locs: ";
//		for(int loc : kust)
//			cout << loc << " ";
//		cout << endl;

		int sk = kust.size();
		if(sk == 0) {
			memset(best[i], 0, sizeof best[i]);
			continue;
		}
		for(int j = 0; j <= min(k, sk); j++) {
//            cout << "   best k="<<j<<endl;
			int mini = kust[sk - 1] - kust[0] + 1;
			for(int l = 0; l <= j; l++) {
				int  alt = sk - (j - l) - 1;
				if(alt < l)
					mini = 0;
				else
					mini = min(mini, kust[alt] - kust[l] + 1);
			}
			best[i][j] = mini;
//            cout << "   ="<<mini<<endl;
		}
	}
	printf("%d\n", f(0, k));
}
