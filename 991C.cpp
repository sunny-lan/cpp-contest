#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll f(ll k){
    ll nn=n;
    ll cnt=0;
    while(nn>0){
        cnt+=min(k, nn);
        nn-=k;
        if(nn>=10)
           nn-=nn/10;
    }
    return cnt;
}

int main(){
    scanf("%lld", &n);
    ll lo=1, hi=(ll)1e18;
  //  for(int i=1;i<10;i++)
    //    printf("%lld\n", f(i));
    while(lo<hi){
        ll mid=(lo+hi)/2;
        ll res=f(mid);
        if(res>=n-res)
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%lld\n", lo);
}
