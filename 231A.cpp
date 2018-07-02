#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<3;j++){
            int d;scanf("%d",&d);
            cnt+=d;
        }
        if(cnt>=2)
            ans++;
    }
    printf("%d\n", ans);
}
