#include <bits/stdc++.h>
using namespace std;

#define MAXN 256

int t[MAXN*2];

int main(){
    int n,a,b;scanf("%d %d %d", &n,&a,&b);
    t[a+n-1]=1;
    t[b+n-1]=1;
    for(int i=n;i>0;i--){
//        printf("%d -> %d, %d\n", i, i*2, i*2+1);
        int ca=t[i*2], cb=t[i*2+1];
        if(ca && cb)
        {
            if(i==1)
                printf("Final!");
            else
            printf("%d", ca);
            break;
        }else if(ca){
            t[i]=ca+1;
        }else if(cb){
            t[i]=cb+1;
        }
    }
}
