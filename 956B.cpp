#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

ll e[MAXN];

int main(){
    int n;ll u;scanf("%d %I64d", &n,&u);
    for(int i=0;i<n;i++)
        scanf("%I64d", &e[i]);
    int k=0;
    double mini=-1;
    for(int i=0;i<n;i++){
        while(k+1<n && e[k+1]-e[i]<=u)
            k++;
        int j=i+1;
        if(e[i]<e[j] && e[j]<e[k])
            mini=max(mini, (e[k]-e[j])/(double)(e[k]-e[i]));
    }
    if(mini==-1)printf("-1");
    else
    printf("%.10lf", mini);
}
