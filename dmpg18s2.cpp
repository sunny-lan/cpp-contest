#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200000

int a[MAXN];

int main(){
    int n;scanf("%d",&n);
    ll tot=0;
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]), tot+=a[i];
    ll res=tot;
    ll af=0;
    for(int i=0;i<n;i++){
        printf("%lld\n", res);
        af+=a[n-1-i];
        tot-=a[i];
        res+=tot;
        res-=af;
    }
}
