#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100

int n;
string a,b;

int dp[MAXN][2][2];

int f(int idx, int af, int bf)
{
    if(idx==n)
    {
        if(af==1)
            return -1000;
        if(bf==1)
            return -1000;
        return 0;
    }
    int &res=dp[idx][af][bf];
    if(res!=-1)
        return res;
    if(a[idx]=='X')
    {
        if(af==1)
            return -1000;
        af=1;
    }
    if(b[idx]=='X')
    {
        if(bf==1)
            return -1000;
        bf=1;
    }
    res=max(res, f(idx+1, 0,0));
    if(af==0 && bf==0)
        res=max(res, max(f(idx+1, 1, 0)+1, f(idx+1, 0,1)+1));
    if(af==0)
        res=max(res, f(idx+1, 1,1)+1);
    if(bf==0)
        res=max(res,f(idx+1, 1,1)+1);
    return res;
}

int main()
{
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>a>>b;
    n=a.length();
    printf("%d\n", f(0,0,0));
}
