#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

typedef long long ll;
typedef pair<int, int> pii;

int disjoint[MAXN];
int n;
void construct() { for (int i = 0; i < n; i++) disjoint[i] = i; }
int find(int x) { if (disjoint[x] == x) return x; return disjoint[x] = find(disjoint[x]); }
bool cmp(int x, int y) { return find(x) == find(y); }
void merge(int x, int y) { disjoint[find(y)] = find(x); }

#define MAXN2 1000

int s, fillN, check;
vector<int> adj[MAXN];
int deg[MAXN];
int odeg[MAXN];
bool inTree[MAXN];
int p[MAXN];
int cnt[MAXN2][MAXN2];
unordered_map<ll, int> cust;

bool active[MAXN2];
int component[MAXN];
bool bridges[MAXN2][MAXN2];
bool cutNodes[MAXN2];
bool blockE[MAXN2][MAXN2];
bool mode;

void dfs(int i, int j) {
	if (s == 5) {
		if (!mode && i >= n)return;
		if (i < n && !active[i])return;
		if (component[i] != check)return;
		component[i] = fillN;
	}
	p[i] = j;
	for (int neigh : adj[i]) {
		if (neigh == j)continue;
		if (s == 5 && i < n && blockE[i][neigh])continue;
		dfs(neigh, i);
	}
}

bool path(int i, int j, int k) {
	if (i == k)return true;
	for (int neigh : adj[i])if (neigh != j)
		if (path(neigh, i, k)) {
			cnt[i][neigh]++, cnt[neigh][i]++;
			return true;
		}
	return false;
}

int main() {
	int t; scan(s); scan(t);
	for (int testCase = 0; testCase < t; testCase++)
	{
		int m; scan(n); scan(m);
		for (int i = 0; i < n; i++) adj[i].clear();
		memset(deg, 0, sizeof deg);
		construct();
		vector<pii> edges;
		if (s == 3 || s == 1) construct();
		for (int i = 0; i < m; i++) {
			inTree[i] = false;
			int a, b; scan(a); scan(b);
			a--, b--;
			edges.push_back({ a,b });
			deg[a]++, deg[b]++;
			if (s == 3 || s == 1) {
				if (cmp(a, b)) continue;
				merge(a, b);
				inTree[i] = true;
			}
			adj[a].push_back(b), adj[b].push_back(a);
		}
		memcpy(odeg, deg, sizeof deg);
		if (s == 2) {
			if (m > n - 1) printf("YES\n");
			else printf("NO\n");
		}
		if (s == 4) {
			for (int i = 0; i < n; i++)if (deg[i] >= 3) goto end4;
			printf("NO\n"); goto end8;
		end4:printf("YES\n"); end8:continue;
		}
		if (s == 1) {
			memset(cnt, 0, sizeof cnt);
			for (int i = 0; i < m; i++)if (!inTree[i]) path(edges[i].first, -1, edges[i].second);
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (cnt[i][j] > 1) goto end1;
			printf("NO\n"); goto end7;
		end1:printf("YES\n"); end7:continue;
		}
		if (s == 3) {
			dfs(0, -1);
			cust.clear();
			int maxi = 0;
			for (int i = 0; i < m; i++)if (!inTree[i]) {
				int a = edges[i].first, b = edges[i].second;
				int mini = INT_MAX;
				int marker = -1;
				for (int j = 0; j <= 4; j++) {
					int tmp = b;
					for (int k = 0; k <= 4; k++) {
						if (tmp == a) {
							int alt = j + k + 1;
							if (alt < mini) {
								mini = alt;
								marker = a;
							}
						}
						if (p[tmp] == -1)break;
						tmp = p[tmp];
					}
					if (p[a] == -1)break;
					a = p[a];
				}
				if (mini < 4) {
					if (marker != -1) {
						a = edges[i].first;
						for (int j = 0; j <= 4; j++) {
							if (a == marker)break;
							if (cust.find(p[a] * 100000 + a) != cust.end() && cust[p[a] * 100000 + a] != i) { printf("YES\n"); goto end3; }
							cust[p[a] * 100000 + a] = i, cust[a * 100000 + p[a]] = i;
							a = p[a];
						}
						for (int j = 0; j <= 4; j++) {
							if (b == marker)break;
							if (cust.find(p[b] * 100000 + b) != cust.end() && cust[p[b] * 100000 + b] != i) { printf("YES\n"); goto end3; }
							cust[p[b] * 100000 + b] = i, cust[b * 100000 + p[b]] = i;
							b = p[b];
						}
					}
				}
				maxi = max(maxi, mini);
			}
			if (maxi >= 4) printf("YES\n");
			else printf("NO\n");
		end3:continue;
		}
		if (s == 5) {
			mode = false;
			memset(active, true, sizeof active);
			check = 0;
			fillN = 1;
			int newN = n;
		next:
			for (int i = 0; i < n; i++)if (deg[i] == 1) {
				deg[i]--;
				for (int neigh : adj[i]) if (active[neigh]) deg[neigh]--;
				active[i] = false;
				goto next;
			}
			int lactive = -1;
			for (int i = 0; i < n; i++) if (active[i]) { lactive = i; break; }
			if (lactive == -1) { printf("NO\n"); goto end5; }
			memset(blockE, false, sizeof blockE);
			memset(bridges, false, sizeof bridges);
			fillN = 1;
			for (pii edge : edges)
			{
				int a = edge.first, b = edge.second;
				if (!active[a] || !active[b])continue;
				memset(component, 0, sizeof component);
				blockE[a][b] = true, blockE[b][a] = true;
				dfs(lactive, -1);
				blockE[a][b] = false, blockE[b][a] = false;
				for (int i = 0; i < n; i++) if (active[i] && component[i] == 0) {
						bridges[a][b] = true, bridges[b][a] = true;
						deg[a]--, deg[b]--;
						break;
					}
			}
			memcpy(blockE, bridges, sizeof bridges);
			for (int i = 0; i < n; i++) if (active[i]) {
				memset(component, 0, sizeof component);
				check = 0,fillN = i + 1;
				dfs(i, -1);
				active[i] = false,check = fillN,fillN = i + 1001;
				for (int neigh : adj[i]) dfs(neigh, i);
				component[i] = fillN,active[i] = true,cutNodes[i] = false;
				for (int j = 0; j < n; j++)if (active[i]) if (component[j] != i + 1001 && component[j] != 0) { cutNodes[i] = true; break; }
				if (cutNodes[i]) {
					int new1 = newN++, new2 = newN++;
					for (int neigh : adj[i])
						if (component[neigh] == i + 1) {
							adj[new1].push_back(neigh), adj[neigh].push_back(new1);
							deg[new1]++, odeg[new1]++;
						}
						else {
							adj[new2].push_back(neigh), adj[neigh].push_back(new2);
							deg[new2]++, odeg[new2]++;
						}
				}
			}
			for (int i = 0; i < n; i++) if (cutNodes[i])active[i] = false;
			mode = true;
			memset(component, 0, sizeof component);
			check = 0;
			for (int i = 0; i < newN; i++) if (active[i]) {
				fillN = i + 1;
				dfs(i, -1);
			}
			for (int i = 0; i < newN; i++)if (active[i]) {
				for (int j = i + 1; j < newN; j++)if (active[j]) {
					if (component[i] != component[j])continue;
					int dj = odeg[j], di = odeg[i];
					if (dj < 3 || di < 3)continue;
					if (dj > 3 || di > 3) { printf("YES\n"); goto end5; }
					for (int k : adj[i]) {
						if (k == j)continue;
						for (int l : adj[j])  if (k == l)goto slkjk;
						printf("YES\n"); goto end5;
					slkjk:continue;
					}
					for (int k : adj[j]) {
						if (k == i)continue;
						for (int l : adj[i]) if (k == l)goto slkjk1;
						printf("YES\n"); goto end5;
					slkjk1:continue;
					}
				}
			}
			printf("NO\n"); end5:continue;
		}
	}
}