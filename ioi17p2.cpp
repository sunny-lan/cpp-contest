#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define f first
#define s second

#define MAXN 200001
ll dp[MAXN];

ll min_total_length(vector<int> r, vector<int> b) {
	vector<pii> pt;
	for(int x : r)
		pt.push_back({x, 0});
	for(int x : b)
		pt.push_back({x, 1});
	sort(pt.begin(), pt.end());
	int n = pt.size();
	vector<int> jpts;
	jpts.push_back(0);
	for(int i = 1; i < n; i++)
		if(pt[i - 1].s != pt[i].s)
			jpts.push_back(i);
	jpts.push_back(n);

	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i + 2 < jpts.size(); i++) {
		int lnkpt = jpts[i + 1] - 1;
		ll k = pt[jpts[i + 1]].f - pt[lnkpt].f, tot = 0, mini = LLONG_MAX;
		set<pii> upd;
		for(int j = jpts[i + 1] - 1; j >= jpts[i]; j--)
		{
			tot += abs(pt[j].f - pt[lnkpt].f);
			ll alt = tot + min(dp[j], dp[j + 1]);
			mini = min(mini, alt);
			if(lnkpt == jpts[i + 1])
				upd.insert({alt, jpts[i + 1] - j - 1});
			else
				lnkpt++;
		}
		ll bcst = pt[jpts[i + 1] ].f - pt[jpts[i + 1] - 1].f;
		dp[jpts[i + 1] + 1] = mini + bcst;
		for(int j = jpts[i + 1] + 1; j < jpts[i + 2]; j++)
		{
			ll vl = k * (j - jpts[i + 1] );
			while(!upd.empty()) {
				auto cur = upd.begin();
				mini = min(mini, cur->f - min(cur->s * k, vl));
				if(vl >= cur->s * k)
					upd.erase(cur);
				else
					break;
			}
			bcst += pt[j].f - pt[jpts[i + 1] - 1].f;
			dp[j + 1] = mini + bcst;
		}
	}

	return dp[n];
}
