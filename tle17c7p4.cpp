#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;

#define MAXN 210001

vector<pic> upd[MAXN];
string s;
int oi[MAXN];


vector<int> srt(vector<int> vals, int dep) {
	if(vals.size() <= 1 || dep >= s.length())
		return vals;
	pic sch = {vals[0], 'z' + 1};
	int idx = upper_bound(upd[dep].begin(), upd[dep].end(), sch) - upd[dep].begin() - 1;
	char kust;
//	int lupd;
	vector<int> res;
	unordered_map<char, vector<int>> derp;
	int mini = INT_MAX;
	for(int i : vals) {
		while(idx < upd[dep].size() && upd[dep][idx].first <= i)
			kust = upd[dep][idx].second, idx++;
		if(oi[i] > dep)
			mini = min(mini, oi[i]);
		derp[kust].push_back(i);
	}
	mini = max(mini, dep + 1);
	for(char c = 'a'; c <= 'z'; c++) {
		vector<int> ree = srt(derp[c], mini);
		res.insert(res.end(), ree.begin(), ree.end());
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> s >> n;

	for(int i = 0; i < s.length(); i++)
		upd[i].push_back({0, s[i]});
	vector<int> kms = {0};
	for(int i = 1; i < n; i++) {
		kms.push_back(i);
		int x;
		char c;
		cin >> x >> c;
		x--;
		oi[i] = x;
		upd[x].push_back({i, c});
	}
	kms = srt(kms, 0);
	int q;
	cin >> q;
	for(int k = 0; k < q; k++)
	{
		int i, j;
		cin >> i >> j;
		i--, j--;
		pic sch = {kms[i], 'z' + 1};
		int idx = upper_bound(upd[j].begin(), upd[j].end(), sch) - upd[j].begin() - 1;
		printf("%c\n", upd[j][idx].second);
	}
}
