#include <bits/stdc++.h>
using namespace std;

#define MAXN 1500
bitset<MAXN> adj[MAXN];

int main(){
    int n,m,k;scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d", &a, &b);
        a--,b--;
        adj[a][b]=adj[b][a]=1;
    }
    for(int i=0;i<n;i++){
        bitset<MAXN> cur, al;
        cur[i]=al[i]=1;
        for(int j=0;j<k;j++){
            bitset<MAXN> nxt;
            for(int k=0;k<n;k++)
                if(cur[k])
                nxt|=adj[k];
            cur=nxt;
            al|=cur;
        }
        printf("%d\n", al.count());
    }
}
