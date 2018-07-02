#include <bits/stdc++.h>
using namespace std;

#define MAXN 10001

int p[MAXN];

int f(int x){
    if(p[x]==x)return x;
    return p[x]=f(p[x]);
}

int main(){
    int n,m;scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d", &a, &b);
        a--,b--;
        int pa=f(a),
        pb=f(b);
        if(pa==pb)continue;
        p[pa]=pb;
    }
    int x,y;scanf("%d %d", &x, &y);
    x--,y--;
    if(f(x)==f(y))
        printf("1");
    else
        printf("0");
}
