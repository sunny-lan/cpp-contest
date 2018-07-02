#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int g[MAXN];

int main(){
    int n;scanf("%d", &n);
    int avg=0;
    for(int i=0;i<n;i++)scanf("%d", &g[i]), avg+=g[i];
    sort(g,g+n);
    int cnt=0;
    for(int i=0;avg*10<45*n && i<n;i++)
        avg-=g[i], avg+=5, cnt++;
    printf("%d\n", cnt);
}
