#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

string w;
int dp[MAXN][MAXN];
int ind;

int f(int l,int r){
//    for(int i=0;i<ind;i++)printf(" - ");
//   printf("[%d, %d] [%c %c]\n", l, r, w[l], w[r-1]);
    if(l>=r)return 1;
    int &res=dp[l][r];
    if(res!=-1)return res;
   res=0;
    if(r!=l+1 && w[l]==w[r-1])
       res|=f(l+1, r-1);
//ind++;
    for(int j=l+1;j<r;j++){
        res|=f(l,j)&f(j,r);
        if(w[j]==w[l]){
//    for(int i=0;i<ind;i++)printf(" - ");
//    printf("m\n");
            res|=f(l+1, j)&f(j, r);
        }
    }
//    ind--;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int kms=0;kms<5;kms++){
    for(int test=0;test<5;test++){
        memset(dp, -1, sizeof dp);
        cin>>w;
        if(f(0, w.length()))
            printf("S");
        else printf("U");
    }
    printf("\n");
    }
}
