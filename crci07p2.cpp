#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
 int n;
int c[MAXN];
int dp[MAXN][MAXN];

int f(int i=0, int j=0){
    if(i>n-1 || i<0)return 1<<30;
    if(i==n-1)return c[i];
    int &res=dp[i][j];
    if(res!=-1)return res;
    res=1<<30;
//    if(i-j>=0)
    res=min(f(i-j,j)+c[i],f(i+j+1,j+1)+c[i]);
    return res;
}

int main(){
    memset(dp, -1, sizeof dp);

   scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d", &c[i]);

        printf("%d\n", f()-c[0]);
}
