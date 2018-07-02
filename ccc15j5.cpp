#include <bits/stdc++.h>
using namespace std;

int bc(int n, int k){
    int num=1,den=1;
    for(int i=1;i<=k;i++)
        num*=n-i+1, den*=i;
    return num/den;
}

int main(){
    int n,k;scanf("%d %d", &n, &k);
    printf("%d\n", bc(n+k-1, n));
}
