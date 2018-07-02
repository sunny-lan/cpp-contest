#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 101
ll dp[MAXN][MAXN][MAXN];
int n, k;
ll f(int idx, int over, int lft) {
    if(lft<0)return 0;
	if(idx == n) {
		if(over == 0 && lft == 0)
			return 1;
		return 0;
	}

	ll &res = dp[idx][over][lft];
	if(res != -1)
		return res;

    //skip
    res=f(idx+1, over, lft);

    //start new
    res+=f(idx+1, over+1, lft);
    res%=MOD;

    //bring down stuff
    for(int j=0;j<over;j++)
        res+=f(idx+1, over-1, lft-j),
        res%=MOD;

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &k);
    printf("%lld\n", f(0, 0, k));
}
