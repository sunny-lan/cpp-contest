#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;scanf("%d%d", &n, &x);
    int lstnm=7-x;
    for(int i=0;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        bool lol[7];
        for(int j=1;j<=6;j++)lol[j]=false;
        lol[7-lstnm]=lol[a]=lol[b]=lol[7-a]=lol[7-b]=true;
        int cc=0;
        for(int j=1;j<=6;j++)
        if(!lol[j]){
            lstnm=j;
            cc++;
        }
       if(cc>1)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
