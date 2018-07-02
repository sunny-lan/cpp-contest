#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int dp[MAXN][MAXN];

int choose(int n,int k){
    if(k==0 || n==k)return 1;
    int &res=dp[n][k];
    if(res!=-1)return res;
    res=choose(n-1, k)+choose(n-1, k-1);
    return res;
}

int main(){
    memset(dp, -1, sizeof dp);
    while(1){
        int n,m;scanf("%d%d",&n,&m);
        if(n==0 &&m==0)break;
        printf("%d things taken %d at a time is %d exactly.\n", n,m,choose(n,m));
    }
}
