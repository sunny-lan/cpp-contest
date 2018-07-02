#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;
typedef long long ll;

vector<pair<int,int>> u[10000];

int main()
{
    int n,m,q;
    scanf("%d %d %d", &n, &m,&q);
    for(int i=0;i<n;i++){
        int w;scanf("%d", &w);
        u[i].push_back({0, w});
    }
    for(int i=1;i<=m;i++){
        int a,p;scanf("%d %d", &a, &p);
        a--;
        upd.push_back({i, {a, p}});
    }
    for(int i=0;i<q;i++){
        int l,r,x;
        scanf("%d %d %d", &l, &r, &x);
    l--;
        int mini=INT_MAX;
        for(auto v:upd){
            if(v.second.second%x==0)
                if(v.second.first>=l && v.second.first<r)
                    mini=min(mini, v.first);
        }
        if(mini==INT_MAX)
            mini=-1;
        printf("%d\n", mini);
    }
}

