#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int c[MAXN], m[MAXN];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&m[i]);
    sort(c,c+n);
    sort(m,m+n);
    int maxi=0;
    for(int i=0;i<n;i++){
            maxi=max(maxi, abs(c[i]-m[i]));
        }
    printf("%d\n", maxi);
}
