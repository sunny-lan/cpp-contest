#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 300010

int dp[MAXN][3];
int idx;
int nxt[MAXN];

// 0=nothing in prev
// 1=prev taken
// 2=prev must be carried

int f(int i, int prev) {
	if (i == idx )
		if (prev == 2)
			return MAXN;
		else
			return 0;
	int &res = dp[i][prev];
	if (res != -1)
		return res;
	res = MAXN;
	if (nxt[i] == -1 || nxt[i]==i || nxt[i]==idx) {
		if (prev == 0)
			res = f(i + 1, 0) + 1;
		else if (prev == 1)
			res = f(i + 1, 0);
		else if (prev == 2)
			res = f(i + 1, 0) + 1;
	}
	else {
		if (prev == 2)
			res = min(res, f(nxt[i], 1) + 1);
		else  if(prev == 1) {
			res = min(res, f(nxt[i], 0));
			res = min(res, f(nxt[i], 1) + 1);
		}
		else if (prev == 0) {
			res = min(res, f(nxt[i], 2));
			res = min(res, f(nxt[i], 1) + 1);
		}
	}
	return res;
}

#define st first
#define ed second

pii lns[MAXN];
int a[MAXN], b[MAXN];

int main() {
	memset(dp, -1, sizeof dp);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &lns[i].st, &lns[i].ed);

	sort(lns, lns + n);
	ll lst = -1;
	for(int i = 0; i < n; i++)
		if(lns[i].ed > lst)
			lst = lns[i].ed, a[idx] = lns[i].st, b[idx] = lns[i].ed,
			 idx++;

    int j=0;
	for (int i = 0; i < idx; i++)
	{
        int lo=i,hi=idx-1;
        while(hi>lo){
            int mid=(lo+hi+1)/2;
            if(a[mid]>=b[i])
                hi=mid-1;
            else
                lo=mid;
        }
        if(a[hi]>=b[i] || hi<=i)
            nxt[i]=-1;
        else
            nxt[i]=hi;
	}

	printf("%d", f(0, 0));
}
