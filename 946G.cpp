#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int a[MAXN];
int pre[MAXN];
int rv[MAXN];
int pv[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) {
		rv[i + 1] = max(rv[i] + 1, a[i]);
		int alt=a[i] <= rv[i] ? 1 : 0;
		pre[i + 1] = pre[i] + alt;
	}

	int cur=INT_MAX;
	for(int i=n-1;i>=0;i--){
        int nxt=cur-1;
        if(a[i])
        cur=max(nxt, a[i]);
	}
}
