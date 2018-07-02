#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int cnt[MAXN];
int ans[MAXN];

int main(){
   int n;scanf("%d", &n);
   for(int i=0;i<n;i++)
   {
       int a;scanf("%d", &a);
       for(int j=0;j<a;j++)
        cnt[j]++;
   }
   for(int i=n-1;i>=0;i--)
        for(int j=0;j<MAXN;j++)
            if(cnt[j]>0)
            ans[i]++, cnt[j]--;
   for(int i=0;i<n;i++)
    printf("%d ", ans[i]);
}
