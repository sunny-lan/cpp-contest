#include <bits/stdc++.h>

using namespace std;

typedef pair<int, double> pid;
#define f first
#define s second

#define MAXN 5005

vector<pid> adj[MAXN];

bool reach[MAXN];
bool vis[MAXN];
void dfs(int i = 0) {
	if(vis[i])
		return;
	vis[i] = true;
	for(pid k : adj[i])
		dfs(k.f), vis[i] |= vis[k.f];
}

int n, m, d;
double du[MAXN];
double sp() {
	for(int i = 1; i < n; i++)
		du[i] = -INFINITY;
	du[0] = log(d);
	for(int it = 0; it < n; it++)
		if(reach[it])
			for(int i = 0; i < n; i++)
				if(reach[i])
					for(pid k : adj[i])
						if(reach[k.f])
							du[k.f] = max(du[k.f], du[i] - k.s);
	for(int i = 0; i < n; i++)
		if(reach[i])
			for(pid k : adj[i])
				if(reach[k.f])
					if(du[k.f] < max(du[k.f], du[i] - k.s))
						return -INFINITY;
	return du[n - 1];
}

int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\SAMPLE2.txt", "r", stdin);
    for(int test=0;test<10;test++){
        memset(reach, false, sizeof reach);
        memset(vis, false, sizeof reach);
        scanf("%d%d%d", &n, &m, &d);
        reach[n-1]=true;
        for(int i = 0; i < n; i++) {
            int a, b;
            double r;
            scanf("%d%d%lf", &a, &b, &r);
            a--, b--;
            if(r!=0)
            adj[a].push_back({b, log(r)});
        }
        dfs();
        double sh=sp();
        if(sh>=log(1e9-200))
            printf("Billionaire!\n");
        else
        printf("%.2lf\n", pow(10, sh));
    }
	return 0;
}

