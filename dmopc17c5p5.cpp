#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200001

struct node {
	node* child[2] = {nullptr, nullptr};
	bool visited = false;
	vector<int> cont;
};

bool vis(node* t) {
	if(t)
		return t->visited;
	return true;
}

int v[MAXN];

node* ins(node *t, int x, int bit = 30) {
	if(!t)
		t = new node();
	if(bit == -1) {
		t->cont.push_back(x);
		return t;
	}
	t->child[(v[x] >> bit) & 1] = ins(t->child[(v[x] >> bit) & 1], x, bit - 1);
	return t;
}

int lbl[MAXN];
int fil = 1;
queue<int> nxt;
void rm(node *t) {
	for(int j : t->cont)
	{
		lbl[j] = fil;
		nxt.push(j);
	}
	t->visited = true;
}

void del(node *t, int x, int bit = 30) {
	if(bit == -1)
		return rm(t);
	del(t->child[(x >> bit) & 1], x, bit - 1);
	t->visited = vis(t->child[0]) && vis(t->child[1]);
}

int n, m, q;

void traverse(node *t, int x, int bit = 30, bool unlock = false) {
	if(!t)
		return;
	if(t->visited)
		return;
	if(bit == -1)
		return rm(t);
	bool flg = (m >> bit) & 1;
	int cloc = (x >> bit) & 1;
	if(unlock || flg) {
		//if m is 1, can produce 1 or 0
		traverse(t->child[0], x, bit - 1, unlock || (flg && !cloc));
		traverse(t->child[1], x, bit - 1, unlock || (flg && cloc));
	} else {
		//if m has 0, must produce 0 (aka must be equal)
		traverse(t->child[cloc], x, bit - 1, false);
	}
	t->visited = vis(t->child[0]) && vis(t->child[1]);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	node* t = new node();
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]), t = ins(t, i);
	for(int i = 0; i < n; i++) {
		if(lbl[i] > 0)
			continue;
		nxt.push(i);
		del(t, v[i]);
		while(!nxt.empty()) {
			int cur = nxt.front();
			nxt.pop();
			traverse(t, v[cur]);
		}
		fil++;
	}

	for(int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		if(lbl[a] == lbl[b])
			printf("YES\n");
		else
			printf("NO\n");
	}
}
