#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int a[MAXN];
int ptr[MAXN];
bool pred(int x,int y){
    return a[x]<a[y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),ptr[i]=i;
    sort(ptr, ptr+n, pred);
    for(int i=0;i<n;i++)
        a[ptr[i]]=i;
    int st,ed;
    for(st=0;st<n && a[st]==st;st++);
    for(ed=n-1;ed>=0&& a[ed]==ed;ed--);
    for(int i=st;i<=ed;i++)
        if(a[st]-(i-st)!=a[i])
    {
        printf("no\n");
        return 0;
    }
    if(st>ed)st=0,ed=0;
    printf("yes\n%d %d\n", st+1,ed+1);
}
