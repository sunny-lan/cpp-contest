#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    int bt=INT_MAX, bst;
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        a-=i;
        int alt=(a+n-1)/n;
        if(alt<bt)
            bt=alt, bst=i;
    }
    printf("%d\n", bst+1);
}
