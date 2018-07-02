#include <bits/stdc++.h>
using namespace std;

int conv(int x,int y){
    x+=1000,y+=1000;
    return x*5000+y;
}

#define MAXN 1001

int px[MAXN],py[MAXN];

int main(){
    int n;scanf("%d",&n);
    unordered_set<int> pos;
    pos.insert(conv(0,0));
    for(int i=1;i<n;i++){
        int p,x,y;scanf("%d %d %d",&p, &x, &y);
        p--;
        pos.insert(conv(px[p]+x,py[p]+y));
        px[i]=px[p]+x,py[i]=py[p]+y;
    }
    printf("%d", pos.size());
}
