#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define f first
#define s second

int main(){
    int l,r,x,y;
    scanf("%d %d %d %d", &l, &r, &x, &y);

    vector<pll> ree;
    for(ll fac=2;(fac*fac<=x || fac*fac<=y) && (x>1 || y>1);fac++){
        ree.push_back({1,1});
        while(x%fac==0)
            ree.back().f*=fac, x/=fac;
        while(y%fac==0)
            ree.back().s*=fac, y/=fac;
        if(ree.back().f>ree.back().s){
            printf("0\n");
            return 0;
        }
        if(ree.back().f==1 && ree.back().s==1)
            ree.pop_back();
    }
    if(x>1 || y>1)
    ree.push_back({x,y});

    unordered_set<ll> res;
    for(int i=0;i<1<<ree.size();i++){
        ll a=1,b=1;
        for(int j=0;j<ree.size();j++)
            if((i>>j)&1)
                a*=ree[j].f, b*=ree[j].s;
            else
                a*=ree[j].s, b*=ree[j].f;
        if(l<=a && a<=r && l<=b && b<=r)
        res.insert((a<<32)|b);
    }

    printf("%d\n", res.size());
}
