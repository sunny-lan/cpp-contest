#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

int x[MAXN];

int main(){
    while(1){
        int n;scanf("%d",&n);
        if(n==0)break;
        int cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
            for(int j=0;j<i;j++)
                if(__gcd(x[i], x[j])==1)cnt++;
        }
        if(cnt==0){
            printf("No estimate for this data set.\n");
            continue;
        }
        double ans=sqrt(3.0*n*(n-1)/cnt);
        printf("%.6lf\n", ans);
    }
}

