#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 150000

int h[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;scanf("%d %d",&n,&k);
    int l=0,tot=0,mini=INT_MAX,bst;
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        tot+=h[i];
        while(l<i-k+1)
            tot-=h[l],l++;
        if(i-l+1==k)
        if(tot<mini)mini=tot,bst=l;
    }
    printf("%d\n", bst+1);
}

