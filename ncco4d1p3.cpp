#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 5001

vector<pii> adj[MAXN];

int da[MAXN], db[MAXN];
bool v[MAXN];
void dijk(int src, int du[]){
    memset(du, 0x3f, sizeof da);
    memset(v, false, sizeof v);
    priority_queue<pii> q;
    q.push({0, src});
    du[src]=0;
    while(!q.empty()){
        int i=q.top().s;q.pop();
        v[i]=true;
        for(pii k:adj[i])
        if(!v[k.f]){
            int alt=du[i]+k.s;
            if(alt<du[k.f])
            du[k.f]=alt, q.push({-alt, k.f});
        }
    }
}

int main(){
    int n,m;scanf("%d %d", &n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,w;scanf("%d %d%d", &a, &b,&w);
        a--,b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dijk(0, da), dijk(n-1, db);
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
        for(pii k:adj[i])
    {
        int alt=da[i]+k.s+db[k.f];
        if(alt<mini && alt>da[n-1])
            mini=alt;
    }
    printf("%d\n", mini);
}
