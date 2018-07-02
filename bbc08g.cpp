#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100001
#define INF 6666666

int n, m;
vector<pii> adj[MAXN];
int p[MAXN], d[MAXN];
unordered_map<int, bool> kms[MAXN];
bool v[MAXN];
int da[MAXN], db[MAXN];

int main() {
	memset(p, -1, sizeof p);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}

	queue<pii> q;
	q.push({n - 1, 0});
	v[n - 1] = true;
	set<int> st;
	while(!q.empty()) {
		pii i = q.front();
		q.pop();
		for(pii k : adj[i.f]) {
			if(v[k.f])
				continue;
			if(k.s == 0)
			{
				q.push({k.f, i.s + 1});
				kms[i.f][k.f] = kms[k.f][i.f] = true;
				p[k.f] = i.f;
				v[k.f] = true;
			} else
				st.insert(i.f);
		}
	}

	int mini2 = -1;
	memset(v, false, sizeof v);
	q.push({0, 0});
	v[0] = true;
	while(!q.empty()) {
		pii i = q.front();
		q.pop();
		da[i.f] = i.s;
		if(mini2 == -1)
			if(st.count(i.f) > 0)
				mini2 = i.s;
		for(pii k : adj[i.f]) {
			if(v[k.f])
				continue;
			if(kms[i.f][k.f])
				continue;
			v[k.f] = true;
			q.push({k.f, i.s + 1});
		}
	}

	memset(v, false, sizeof v);
	for(int i : st)
		q.push({i, 0}), v[i] = true;
	while(!q.empty()) {
		pii i = q.front();
		q.pop();
		db[i.f] = i.s;
		for(pii k : adj[i.f]) {
			if(v[k.f])
				continue;
			if(kms[i.f][k.f])
				continue;
			v[k.f] = true;
			q.push({k.f, i.s + 1});
		}
	}

	for(int i = 0; i < n; i++)
		for(pii k : adj[i]) {
			if(kms[i][k.f])
				continue;
			int a = i, b = k.f;
			if(da[a] + db[b] + 1 <= mini2)
				continue;
			if(da[b] + db[a] + 1 <= mini2)
				continue;
			kms[i][k.f] = kms[k.f][i] = true;
		}

	memset(v, false, sizeof v);
	while(!st.empty()) {
		set<int> nxt;
		int mini = 10;
		for(int i : st) {
			if(k.f == 0)
				goto outer;
			v[i] = true;
			for(pii k : adj[i])
			{
				if(v[k.f])
					continue;
				if(kms[i][k.f])
					continue;
				if(k.s < mini)
					nxt.clear(), mini = k.s;
				if(k.s == mini)
					nxt.insert(k.f), p[k.f] = i, d[k.f] = k.s;

			}
		}
		st = nxt;
	}

outer:
	string t = "";
	int tmp = 0;
	vector<int> nd;
	while(tmp != -1) {
		nd.push_back(tmp);
		t += d[tmp] + '0';
		tmp = p[tmp];
	}
	reverse(t.begin(), t.end());
	bool flg = false;
	for(char c : t) {
		if(c != '0')
			flg = true;
		if(flg)
			printf("%c", c);
	}
	if(!flg)
		printf("0");
	printf("\n");
	printf("%d\n", nd.size());
	for(int i : nd)
		printf("%d ", i);
	printf("\n");

}
