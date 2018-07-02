#include <bits/stdc++.h>
using namespace std;

#define MAXN 2010

int a[MAXN];

int dp[MAXN][2][MAXN];
int psa[2][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        psa[0][i+1]=psa[0][i];
        psa[1][i+1]=psa[1][i];
        psa[a[i]-1][i+1]++;
    }
    for(int st=n-1; st>=0; st--)
    {
        for(int i=st; i>=0; i++)
        {
            dp[st][0][i]=dp[st][0][i-1]+(a[i]==1?1:0);
            dp[st][1][i]=dp[st][1][i-1];
            if(a[i]==2)
                dp[st][1][i]=max(dp[st][1][i], max(dp[st][0][i-1]+1, dp[st][1][i-1]+1));
        }
    }
    int maxi=0;
    for(int i=0;i<=n;i++)
        maxi=max(maxi, psa[0][i]+psa[1][n]-psa[1][i]);
    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++)
            maxi=max(maxi, psa[0][l]+dp[r][1][l]+psa[1][n]-psa[1][r+1]);
    printf("%d", maxi);
}
