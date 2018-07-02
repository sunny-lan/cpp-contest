#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define MAXN 100000
int a[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i+3<=n;i++){
        if(a[i]+a[i+1]>a[i+2]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}

