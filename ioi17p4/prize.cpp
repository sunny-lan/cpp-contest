#include "prize.h"

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

struct node {
	vector<int> mp;
	node* l = nullptr, *r = nullptr;
	int qpos = -1;
	node() {}
};

void traverse(node* t, int snum) {
	if(ans != -1)
		return;
	if(!t)
		return;
	int i = (t->mp.size() - 1) / 2;
	if(i == -1)
		return;
	int j = t->mp[i];
	if(nani(j).first + nani(j).second != snum) {
		if(ans != -1)
			return;
		t->mp.erase(t->mp.begin() + i);
		t->l = t->r = nullptr;
		return;
	}
	t->qpos = j;
	traverse(t->l, snum), traverse(t->r, snum);
}

int find_best(int n) {
	memset(dp, -1, sizeof dp);

	node* stree = new node();
	for(int i = 0; i < n; i++)
		stree->mp.push_back(i);

	int snum;
	unordered_map<int, int> cnt;

	queue<node*> q;
	q.push(stree);

	double thres = 0.5 * (sqrt(4 * stree->mp.size() + 1) - 1);
	while(!q.empty()) {
		node* cur = q.front();
		q.pop();
		if(cur->mp.empty())
			break;
		int mid = (cur->mp.size() - 1) / 2;
		pii res = nani(cur->mp[mid]);
		if(ans != -1)
			return ans;
		if(++cnt[res.first + res.second] > thres) {
			snum = res.first + res.second;
			break;
		}
		cur->l = new node();
		for(int i = 0; i < mid; i++)
			cur->l->mp.push_back(cur->mp[i]);
		cur->r = new node();
		for(int i = mid + 1; i < cur->mp.size(); i++)
			cur->r->mp.push_back(cur->mp[i]);
		q.push(cur->l);
		q.push(cur->r);
	}

	traverse(stree, snum);
	if(ans != -1)
		return ans;

	int sch = 0;
	while(true) {
		node* cur = stree;
		int lst = cur->qpos;
		while(cur->mp.size() > 1) {
			pii res;
			int mid = (cur->mp.size() - 1) / 2;
			if(cur->qpos == - 1) {
				res = nani(cur->mp[mid]);
			} else
				res = nani(cur->qpos);
			if(ans != -1)
				return ans;
			if(res.first + res.second == snum) {
				if(cur->qpos == -1)
					cur->qpos = cur->mp[mid];
				if(res.first <= sch)
				{
					lst = cur->qpos + 1;
					if(!cur->r) {
						cur->r = new node();
						for(int i = mid + 1; i < cur->mp.size(); i++)
							cur->r->mp.push_back(cur->mp[i]);
					}
					cur = cur->r;
				}
				else {
					if(!cur->l) {
						cur->l = new node();
						for(int i = 0; i < mid; i++)
							cur->l->mp.push_back(cur->mp[i]);
					}
					cur = cur->l;
				}
			} else {
				lst = cur->mp[mid];
				cur->mp.erase(cur->mp.begin() + mid);
			}
		}
		nani(lst);
		if(ans != -1)
			return ans;
		if(lst == n - 1)
			break;
		sch++;
	}
}
