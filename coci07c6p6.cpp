#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int a[MAXN], b[MAXN];

int main(){
    int n;scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d %d", &a[i], &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    ll orig=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){

        }
        orig+=abs(a[i]-b[i]);

    }
}
