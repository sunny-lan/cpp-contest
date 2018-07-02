#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 100000

vector<int> fadj[MAXN];
vector<int> badj[MAXN];
void bfs(vector<int> adj[], int d[]){
    queue<pii> q;
    q.push({0,0});
    while(!q.empty()){
        pii i=q.front();
        q.pop();
        if(d[i.f]!=-1)continue;
        d[i.f]=i.s;
        for(int k:adj[i.f])
        q.push({k, i.s+1});
    }
}

int da[MAXN], db[MAXN];

int main(){
    memset(da, -1, sizeof da);
    memset(db, -1, sizeof db);
    int n,m;scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d", &a, &b);
        a--,b--;
        fadj[a].push_back(b);
        badj[b].push_back(a);
    }

    bfs(fadj, da); bfs(badj, db);

    int k;scanf("%d", &k);
    ll tot=0;
    for(int i=0;i<k;i++){
        int s;scanf("%d", &s);
        s--;
        if(da[s]==-1 || db[s]==-1){
            printf("-1\n");
            return 0;
        }
        tot+=da[s]+db[s];
    }

    printf("%lld\n", tot);
}
