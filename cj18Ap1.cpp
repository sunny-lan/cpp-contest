#include <bits/stdc++.h>
using namespace std;

#define MAXN 250

int n,l;
int c[MAXN];
int dp[MAXN][MAXN];

int rr(int x){
    double y=x*100.0/(double)n;
    if(y+0.5>=1+(int)y)
        return 1+(int)y;
    return (int)y;
}

int f(int i, int j){
    if(i==n) {
        if(j==l)return 0;
        else return -(1<<30);
    }

    int &res=dp[i][j];
    if(res!=-1)return res;
    res=-(1<<30);

    for(int nxt=i+1;nxt<=n;nxt++){
        int nm=nxt-i;
        if(j!=l && nm>=c[j])
            res=max(res, f(nxt,j+1)+rr(nm));
        else
            res=max(res, f(nxt, j)+rr(nm));
    }
    return res;
}

int main(){
    int t;scanf("%d", &t);
    for(int test=1;test<=t;test++){
        memset(dp, -1, sizeof dp);
        scanf("%d%d", &n,&l);
        for(int i=0;i<l;i++)
            scanf("%d", &c[i]);
        printf("Case #%d: %d\n", test, f(0,0));
    }
}
