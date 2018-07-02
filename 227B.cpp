#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 100001

int ord[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        ord[a]=i;
    }
    int m;scanf("%d",&m);
    ll v=0,p=0;
    for(int i=0;i<m;i++){
        int b;scanf("%d",&b);
        v+=ord[b]+1;
        p+=n-ord[b];
    }
    printf("%lld %lld\n", v,p);
}
