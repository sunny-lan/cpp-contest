#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXK 101
int n,k;
int l[MAXK],r[MAXK];

int dp[MAXK][MAXN];
int f(int i, int j){

    int &res=dp[i][j];
    if(res!=-1)return res;
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++)
        scanf("%d %d", &l[i], &r[i]);

}
