#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 1010

int l[MAXN];int psa[MAXN];

//int dp[MAXN][MAXN];
int mid[MAXN][MAXN];
int f(int i, int j){
    if(j-i<=1)return 0;
//    int &res=dp[i][j];
//    if(res!=-1)return res;
//    res=1<<30;
//    for(int k=i+1;k<j;k++)
    int k=mid[i][j];
        return f(i,k)+f(k,j)+psa[j]-psa[i];
//    return res;
}

int main(){
//    memset(dp, -1, sizeof dp);

    int n;scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &l[i]), psa[i+1]=psa[i]+l[i];

    for(int i=0;i<n;i++){
        int ptr=i;
        for(int j=i;j<=n;j++){
            while(ptr<j && (psa[ptr]-psa[i])*2<(psa[j]-psa[i]))
                ptr++;
            mid[i][j]=ptr;
        }
    }

    printf("%d\n", f(0,n));
}
