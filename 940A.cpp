#include <bits/stdc++.h>
using namespace std;

int a[101];

int main(){
    int n,d;scanf("%d %d", &n, &d);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a,a+n);
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[j]-a[i]<=d)
                mini=min(mini, i+(n-j-1));
        }
    }
    printf("%d\n", mini);
}
