#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 501
#define MOD 1000000007

ll choose(int n, int k){

}

int h[MAXN];
int w[MAXN], h[MAXN];
int lc[MAXN], rc[MAXN];

int idx=0;
int init(int ll, int rr, int ph=0){
    if(ll+1==rr){
        return -1;
    }
    w[i]=rr-ll;
    int mini=INT_MAX, bst;
    for(int i=ll;i<rr;i++){
        if(h[i]<mini)
            mini=h[i],bst=i;
    }
    h[i]=mini-ph;
    lc[idx]=init(ll, bst, mini);
    rc[idx]=init(bst, rr, mini);
    return idx++;
}

ll dp[MAXN][MAXN];
ll calc(int i){

    calc(lc[i]), calc(rc[i]);
}

int main(){
    int n,k;scanf("%d%d", &n,&k);
    for(int i=0;i<n;i++)
        scanf("%d", &h[i]);
}
