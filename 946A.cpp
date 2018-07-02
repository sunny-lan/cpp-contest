#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d", &n);
    int x=0,y=0;
    for(int i=0;i<n;i++)
       {

           int a;scanf("%d", &a);
           if(a<0)
            x+=a;
           else
            y+=a;
       }

    printf("%d\n", abs(x-y));
}
