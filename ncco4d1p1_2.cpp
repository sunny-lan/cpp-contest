#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 20000

int l[MAXN];

int main(){
    memset(dp, -1, sizeof dp);

    int n;scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &l[i]);

    sort(l,l+n);

    for(int i=n-1;i++){

    }

    printf("%lld\n", f(0,n));
}
