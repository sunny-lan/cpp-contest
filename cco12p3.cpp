#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define MAXN 27
#define MAXL 31

unordered_map<char, int> mp;

vector<char> dr[MAXN];
vector<pii> br[MAXN];

string dst;

int dp[MAXL][MAXL][MAXN];
int f(int i, int j, int v) {
	int &res = dp[i][j][v];
	if(res != -1)
		return res;
	res = 0;
	if(j == i + 1) {
		for(char c : dr[v])
			if(c == dst[i]) {
				res = 1;
				break;
			}
	} else
		for(pii rule : br[v])
			for(int spl = i + 1; spl < j; spl++)
				res |= f(i, spl, rule.first)&f(spl, j, rule.second);

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v, t;
	cin >> v >> t;
	int n = 0;
	for(int i = 0; i < v; i++) {
		string c;
		cin >> c;
		mp[c[0]] = n++;
	}
	for(int i = 0; i < t; i++) {
		string c;
		cin >> c;
	}
	int r1;
	cin >> r1;
	for(int i = 0; i < r1; i++) {
		string vv, tt;
		cin >> vv >> tt;
		dr[mp[vv[0]]].push_back(tt[0]);
	}

	int r2;
	cin >> r2;
	for(int i = 0; i < r2; i++) {
		string vv, v1, v2;
		cin >> vv >> v1 >> v2;
		br[mp[vv[0]]].push_back({mp[v1[0]], mp[v2[0]]});
	}

	int w;
	cin >> w;
	for(int i = 0; i < w; i++) {
		memset(dp, -1, sizeof dp);
		cin >> dst;
        printf("%d\n", f(0, dst.length(), 0));
	}
}
