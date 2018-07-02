#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

ll nm[MAXN];
ll mi[MAXN];

int main(){
    int n;scanf("%d", &n);
    ll maxi=0;
    for(int i=0;i<n;i++){
        ll m;scanf("%I64d", &m);
        mi[i]=m;
        nm[i]=max(0ll, maxi-m);
        maxi=max(maxi,m);
    }

    ll cur=0, tot=0;
    for(int i=n-1;i>=0;i--){
        cur=max(0ll, cur-1);
       tot+=max(nm[i], cur-mi[i]);
        cur=max(cur, mi[i]);
    }

    printf("%I64d", tot);
}
