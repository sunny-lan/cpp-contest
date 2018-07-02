#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x;scanf("%d", &x);
        for(int s=0;s<=x;s+=7){
            int other=x-s;
            if(other%3==0)
            {
                printf("YES\n");
                goto outer;
            }
        }
        printf("NO\n");
        outer:continue;
    }
}
