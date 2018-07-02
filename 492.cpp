#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 1000

int a[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l;scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int kek=unique(a,a+n)-a;
    int mx=0;
    for(int i=1;i<kek;i++){
       mx=max(mx, a[i]-a[i-1]);
    }
    mx=max(mx, 2*max(a[0], l-a[kek-1]));
    printf("%lf\n", mx/2.0);
}
