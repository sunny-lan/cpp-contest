#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

int main(){
    int n;scanf("%d",&n);
    int lh=0;
    ll tlost=0, mpt=0;
    for(int i=0;i<n;i++){
        int h;scanf("%d", &h);
        tlost+=h-lh;
        mpt=max(mpt, tlost);
        lh=h;
    }
    printf("%lld\n", mpt);
}
