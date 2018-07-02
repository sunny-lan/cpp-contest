#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    unordered_map<int,int> cnt;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d", &x);
        cnt[x]++;
        mini=min(mini, x);
        maxi=max(maxi, x);
    }

    if(maxi-mini<2){
        printf("%d\n", n);
        for(auto v:cnt)
            for(int i=0;i<v.second;i++)
            printf("%d ", v.first);
        return 0;
    }

    int tot=cnt[mini+1]+cnt[mini+2]*2;
//    printf("tot=%d mini=%d\n", tot, mini);
    int res=INT_MAX, bo, bt,bz;
    for(int ons=0;ons<=min(n, tot);ons++){
        int ned=tot-ons;
        if(ned<0)continue;
        if(ned%2==1)continue;
        int nt=ned/2;
        int zer=n-ons-nt;
        if(zer<0)continue;
//        printf("0=%d 1=%d 2=%d\n", zer, ons, nt);
        int alt=min(cnt[mini], zer)+ min(cnt[mini+1], ons)+ min(cnt[mini+2], nt);
        if(alt<res){
            res=alt;
            bo=ons,bt=nt, bz=zer;
        }
    }
    printf("%d\n", res);
    for(int i=0;i<bo;i++)
        printf("%d ", mini+1);
    for(int i=0;i<bt;i++)
        printf("%d ", mini+2);
    for(int i=0;i<bz;i++)
        printf("%d ", mini);
}
