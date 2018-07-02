#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 10001

bool dpu[MAXN][MAXN];
int dpi[MAXN][MAXN];
int a[MAXN];
int pre[MAXN];

int main() {
	memset(dpi, -1, sizeof dpi);
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dpu[0] = true;
	dpi[0] = 0;
	for(int i = 0; i < n; i++) {
		int b;
		scanf("%d", &b);
		if(b) {
			for(int j = MAXN; j - a[i] >= 0; j++)
				if(dpi[j - a[i]] != -1)
					dpi[j] = max(dpi[j], dpi[j - a[i]] + 1);
		} else {
			for(int j = MAXN; j - a[i] >= 0; j++)
				dpu[j] |= dpu[j - a[i]] ;
		}
	}
	for(int i = 1; i < n; i++)
		pre[i] = max(pre[i], pre[i - 1]);
	int maxi = 0;
	for(int i = 0; i < n; i++)
		if(dpu[i])
		{
		    if(i>r)break;
            if(i<l)
                maxi=max(maxi, pre[min(r+(l-i), n-1)]-1);

		}
}
