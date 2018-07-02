#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXN 100010
int a[MAXN];
ll psa[MAXN*2];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int s,f;scanf("%d %d", &s, &f);
    for(int i=0; i<n; i++)
        psa[ s-i]+=a[i],
        psa[f-i]-=a[i];
    ll sum=0, maxi=-1;
    int best;
    for(int i=-n;i<=n;i++){
        printf("psa[%d]=%lld\n", i, psa[i]);
        sum+=psa[i];
        if(sum>maxi)
            maxi=sum,best=i;
    }
    printf("%d\n", best);
}
