#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 200001

pii dp[MAXN];
int ans = -1;
pii nani(int i) {
	if(dp[i].first == -1) {
		auto res = ask(i);
		dp[i] = {res[0], res[1]};
	}
	if(dp[i].first + dp[i].second == 0)
		ans = i;
	return dp[i];
}

#define THRES 446

int find_best(int n) {
	memset(dp, -1, sizeof dp);
	int snum = 0;

	unordered_map<int, int> cnt;
	int idx = 0;
	while(true) {
		pii res = nani(idx);
		if(ans != -1)
			return ans;
		if(++cnt[res.first + res.second] > THRES)
		{
			snum = res.first + res.second;
			break;
		}
		idx++;
	}
	vector<int> mapping;
	for(int i = 0; i < n; i++)
		mapping.push_back(i);
	set<int> kusts;
	for(int i = idx; i >= 0; i--)
		if(nani(i).first + nani(i).second != snum)
			kusts.insert(i),
						 mapping.erase(mapping.begin() + i);

	int sch = 0;
	while(nani(*kusts.rbegin()).second > 0) {
		int lo = -1, hi = mapping.size() - 1; //(lo,hi]
		while(lo < hi) {
			int mid = (lo + hi + 1) / 2;
			pii res = nani(mapping[mid]);
			if(ans != -1)
				return ans;
			if(res.first + res.second == snum) {
				if(res.first <= sch)
					lo = mid;
				else
					hi = mid - 1;
			} else {
				hi--;
				kusts.insert(mapping[mid]);
				mapping.erase(mapping.begin() + mid);
			}
		}
		kusts.insert(mapping[hi] + 1);
		sch++;
	}

	for(int i : kusts) {
		nani(i);
		if(ans != -1)
			return ans;
	}
}
