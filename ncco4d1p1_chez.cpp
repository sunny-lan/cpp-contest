#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;scanf("%d", &n);
    priority_queue<ll> q;
    for(int i=0;i<n;i++){
        ll l;scanf("%lld", &l);
        q.push(-l);
    }
    ll tot=0;
    while(q.size()>1){
        ll a=-q.top();
        q.pop();
        ll b=-q.top();
        q.pop();
        tot+=a+b;
        q.push(-(a+b));
    }
    printf("%lld\n", tot);
}
