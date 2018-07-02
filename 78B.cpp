#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 100001

char kek[]="GBIV";

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;scanf("%d",&n);
    printf("ROYGBIV");
    n-=7;
    for(int i=0;i<n;i++){
        printf("%c",kek[i%4]);
    }
}

