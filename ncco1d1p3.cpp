#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;



int main(){
    int n,m,c;scanf("%d %d %d", &n, &m, &c);
    deque<pii> maxi, mini;
    set<int> res;
    for(int i=0;i<n;i++){
        int l;scanf("%d", &l);
        while(!maxi.empty() && maxi.back().first<l)
            maxi.pop_back();
        maxi.push_back({l,i});
        while(!maxi.empty() && maxi.front().second<=i-m)
            maxi.pop_front();

        while(!mini.empty() && mini.back().first>l)
            mini.pop_back();
        mini.push_back({l,i});
        while(!mini.empty() && mini.front().second<=i-m)
            mini.pop_front();

        if(i>=m-1 && maxi.front().first-mini.front().first<=c)
            res.insert(i-m+1);
    }
    if(res.empty())
        printf("NONE");
    for(int i:res)
        printf("%d\n", i+1);
}
