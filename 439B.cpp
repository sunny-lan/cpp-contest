#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int c[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    sort(c,c+n);
    ll tot=0;
    for(int i=0;i<n;i++)
        tot+=(ll)c[i]*x,
        x=max(1,x-1);
    printf("%lld\n", tot);
}
