#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000

int lin[MAXN], h[MAXN];

int main(){
    int n;scanf("%d",&n);
    int lst=INT_MAX;
    for(int i=0;i<n;i++){
        scanf("%d", &h[i]);
        if(h[i]>=lst)
            lin[i]=lin[i-1]+1;
        else lin[i]=1;
        lst=h[i];
    }
    lst=INT_MAX;
    int cont=0, ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(h[i]<lst)
            cont=0;
        else
            cont++;
        ans=max(ans, lin[i]+cont);
        lst=h[i];
    }
    printf("%d\n", ans);
}
