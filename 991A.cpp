#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,n;scanf("%d %d %d %d", &a, &b, &c, &n);
    if(n==0){
        printf("-1\n");
        return 0;
    }
    int kek=n-((a-c)+(b-c)+c);
    if(a>n || b>n || c>n  ||kek>n || kek<1){
        printf("-1\n");
        return 0;
    }
    if(c>a || c>b){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", kek);
}
