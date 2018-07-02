#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
int sl[MAXN], sg[MAXN];
int main(){
    int l,g;scanf("%d %d", &l, &g);
    vector<int> t;
    for(int i=0;i<l;i++){
        scanf("%d", &sl[i]);
        t.push_back(sl[i]);
    }
    for(int i=0;i<g;i++){
        scanf("%d", &sg[i]);
        t.push_back(sg[i]);
    }
    t.push_back(1);
    t.push_back(INT_MAX);
    sort(sl, sl+l);
    sort(sg, sg+g);
    sort(t.begin(), t.end());
    int i=0,j=0;
    for(int x:t){
        while(i<l && sl[i]<x)i++;
        while(j<g && sg[j]<x)j++;
        if(g-j>l-i)
        {
            printf("%d", x);
            return 0;
        }
    }
    printf("-1");
}
