#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

vector<int> adj[MAXN];
bool blocked[MAXN];
int sz[MAXN];
void dfs(int i, int j=-1){
    if(blocked[i])return;
    sz[i]=1;
    for(int neigh:adj[i])
        if(neigh!=j)
            dfs(neigh, i),
            sz[i]+=sz[neigh];
}

void centroid(int )

int main(){
    int n;scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a,b;scanf("%d %d", &a, &b);
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}
