#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 400000

int r[MAXN], c[MAXN];
vector<int> adj[MAXN];
int deg[MAXN];

int v[MAXN];
int fil = 1;
void dfs(int i) {
	if(v[i])
		return;
	v[i] = fil;
	for(int k : adj[i])
		dfs(k);
}

pii mc[MAXN + 10];

ll ans[MAXN];

int main() {
    memset(mc, 0x3f, sizeof mc);


	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d %d %d", &r[i], &c[i], &k);
		for(int j = 0; j < k; j++) {
			int b;
			scanf("%d", &b);
			b--;
			adj[i].push_back(b);
			deg[b]++;
		}
	}

	vector<pii> nd;

	for(int i = 0; i < n; i++)
		if(deg[i] == 0)
			nd.push_back({r[i],c[i]}), dfs(i);

	for(int i = 0; i < n; i++)
		if(!v[i])
			fil++, dfs(i);

    for(int i=0;i<n;i++)
        printf("%d[%d] ", v[i], deg[i]);
    printf("\n");

	for(int i = 0; i < n; i++)
        if(v[i]>1)
		mc[v[i]] = min(mc[v[i]], {r[i], c[i]});
//		printf("re %d %d\n", r[i], c[i]);

	for(int i = 0; i < n; i++)
		if(mc[i].first <0x3f3f3f3f)
			nd.push_back(mc[i]);

	int m;
	scanf("%d", &m);

	vector<pii> query;
	for(int i=0;i<m;i++)
    {

        int dsf;scanf("%d", &dsf);
        query.push_back({dsf,i});
    }

    sort(query.begin(), query.end());
    sort(nd.begin(), nd.end());

//    for(pii v:query){
//        cout << v.first<<" "<<v.second<<endl;
//    }
//
    cout << "fds"<<endl;

    for(pii v:nd){
        cout << v.first<<" "<<v.second<<endl;
    }


    int ptr=0, lst=0, tc=0;
    ll tot=0;
    for(pii q:query){
                    cout << q.first<<" "<<q.second<<endl;
        tot+=tc*(q.first-lst);
    cout << "tot="<<tot<<endl;
        while(ptr<nd.size() && nd[ptr].first<=q.first)

                    cout << " d" << nd[ptr].first<<" "<<nd[ptr].second<<endl,
            tc+=nd[ptr].second,
             tot+=nd[ptr].second*(q.first-nd[ptr].first), ptr++;
        lst=q.first;
        ans[q.second]=tot;
    }
    for(int i=0;i<m;i++)
        printf("%lld\n", ans[i]);

}

