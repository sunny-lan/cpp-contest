#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000000

ll magic[7][7] = {
	{1, 1, 0, 1, 2, 1, 0},
	{1, 1, 0, 1, 1, 1, 0},
	{1, 1, 0, 1, 0, 1, 0},
	{4, 2, 1, 2, 0, 2, 1},
	{1, 1, 0, 1, 0, 1, 0},
	{1, 1, 0, 1, 1, 1, 0},
	{1, 1, 0, 1, 0, 1, 0}
};

int n;

void cmb(ll a[7][7], ll b[7][7], ll c[7][7]) {
	for(int i = 1; i < 7; i++)
		for(int j = 1; j < 7; j++)
		{
			ll sm = 0;
			for(int k = 1; k < 7; k++)
				sm += a[i][k] * b[k][j], sm %= MOD;
			c[i][j] = sm;
		}
}

ll cur[7][7];
ll res[7][7], tmp[7][7];

int main() {
	scanf("%d", &n);
	if(n == 1) {
		printf("0\n");
		return 0;
	}
	if(n == 2) {
		printf("1\n");
		return 0;
	}
	n -= 3;
	memcpy(cur, magic, sizeof cur);
	for(int i = 1; i < 7; i++)
		res[i][i] = 1;
	while(n) {
		if(n & 1)
			cmb(res, cur, tmp), memcpy(res, tmp, sizeof res);
		cmb(cur, cur, tmp), memcpy(cur, tmp, sizeof cur);
		n >>= 1;
	}
	ll tot = 0;
	for(int i = 1; i < 7; i++)
		for(int j = 1; j < 7; j++)
			tot += magic[0][i] * res[i][j] * magic[j][0], tot %= MOD;
	printf("%lld\n", tot);
}
