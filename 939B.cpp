#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;int k;scanf("%I64d %d", &n, &k);
    ll maxi=-1, nbr;
    int best;
    for(int i=1;i<=k;i++){
        ll a;scanf("%I64d", &a);
        ll pbx=n/a;
        ll alt=pbx*a;
        if(alt>maxi){
            maxi=alt;
            nbr=pbx;
            best=i;
        }
    }
    printf("%d %I64d", best, nbr);
}
