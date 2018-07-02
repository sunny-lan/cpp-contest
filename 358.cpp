#include <bits/stdc++.h>
using namespace std;

int main(){
    int b[3];
    for(int i=0;i<3;i++){
        int a[3];
        for(int j=0;j<3;j++)
            scanf("%d", &a[j]);
        sort(a, a+3);
        b[i]=a[1];
    }
    sort(b, b+3);
    printf("%d\n", b[1]);
}
