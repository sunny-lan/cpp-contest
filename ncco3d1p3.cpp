#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXR 30

int g[MAXR][MAXR], nd[MAXR][MAXR];

#define MAXN 900

int r, c;
bool inb(int i, int j) {
	return i >= 0 && j >= 0 && i < r && j < c;
}

vector<pii> adja[MAXN], adjb[MAXN];
void conn(int di, int dj, int si, int sj) {
	if(!inb(di, dj))
		return;
	if(g[di][dj] == 2)
		return;
	int cst = g[di][dj] == 0 ? 1 : 0;
	int a = nd[si][sj], b = nd[di][dj];
	adja[a].push_back({b, cst});
	adjb[b].push_back({a, cst});
}

int da[MAXN], db[MAXN];
bool inq[MAXN];
void dijk(int src, int du[], vector<pii> adj[]) {
	memset(du, 0x3f, sizeof da);
	memset(inq, false, sizeof inq);
	priority_queue<pii> q;
	q.push({0, src});
	du[src] = 0;
	while(!q.empty()) {
		int i = q.top().s;
		q.pop();
		inq[i] = false;
		for(pii k : adj[i]) {
			int alt = du[i] + k.s;
			if(alt < du[k.f]) {
				du[k.f] = alt;
				if(!inq[k.f])
					q.push({-alt, k.f}), inq[k.f] = true;
			}
		}
	}
}

unordered_map<int,int> adjn[MAXN];

int src, dst;
unordered_map<int,ll> dp[MAXN];
bool gd[MAXN];
ll f(int i,int kk=0) {
    if(i==dst)
    {
        if(kk==da[dst])
        return 1;
        else
            return 0;
        }
    if(dp[i].find(kk)!=dp[i].end())return dp[i][kk];
    dp[i][kk]=0;
    ll res=0;
    bool isg=g[i/c][i%c]!=0;
    for(pii k:adjn[i])
        {
            if(isg && gd[k.f])continue;
                if(isg )gd[k.f]=true;
        res+=f(k.f, kk+k.s);

        }
    return dp[i][kk]=res;
}

int main() {
//	memset(dp, -1, sizeof dp);

	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &g[i][j]),
				  nd[i][j] = i * c + j;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++) {
			if(g[i][j] == 3)
				src = nd[i][j];
			if(g[i][j] == 4)
				dst = nd[i][j];
			if(g[i][j] == 2)
				continue;
			conn(i - 1, j - 2, i, j);
			conn(i - 2, j - 1, i, j);
			conn(i + 1, j - 2, i, j);
			conn(i + 2, j - 1, i, j);
			conn(i - 1, j + 2, i, j);
			conn(i - 2, j + 1, i, j);
			conn(i + 1, j + 2, i, j);
			conn(i + 2, j + 1, i, j);
		}
	dijk(src, da, adja), dijk(dst, db, adjb);
	if(da[dst] >= 0x3f3f3f3f){
//		printf("-1\n");
		return 0;
}
	for(int i = 0; i < r * c; i++)
		for(pii k : adja[i])
			if(da[i] + db[k.f] + k.s == da[dst]){
                if(adjn[i].find(k.f)==adjn[i].end())
                    adjn[i][k.f]=1<<30;
				adjn[i][k.f]=min(adjn[i][k.f], k.s);
			}
    printf("%d\n%lld\n",da[dst], f(src));
}
