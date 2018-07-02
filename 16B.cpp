#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

ll cnt[11];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        cnt[b]+=a;
    }
    ll tot=0, ptr=10;
    while(n>0)
    {
        while(cnt[ptr]==0 && ptr>0)
            ptr--;
        if(ptr==0)
            break;
        ll amt=min((ll)n, cnt[ptr]);
        cnt[ptr]-=amt;
        n-=amt;
        tot+=amt*ptr;
    }
    printf("%lld\n", tot);
}

