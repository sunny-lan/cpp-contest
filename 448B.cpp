#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define MAXN 100000

int p[MAXN], c[MAXN];
int ptr[MAXN];

bool pred(int a, int b){
    return p[a]<p[b];
}

ll ans[MAXN];

int main(){
    int n,k;scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
        scanf("%d", &p[i]), ptr[i]=i;
    for(int i=0;i<n;i++)
        scanf("%d", &c[i]);

    sort(ptr, ptr+n, pred);

    ll sm=0;
    multiset<int> cns;
    for(int ii=0;ii<n;ii++){
        int i=ptr[ii];
        ans[i]=sm;
        sm+=c[i];
        cns.insert(c[i]);
        while(cns.size()>k)
            sm-=*cns.begin(), cns.erase(cns.begin());
    }

    for(int i=0;i<n;i++)
        printf("%lld ", ans[i]+c[i]);
}
