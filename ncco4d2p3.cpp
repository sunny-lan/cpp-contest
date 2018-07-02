#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int m = 3, alph = 1000002;
int mod[m] = {1000000007, 1000000009, 1000000021};
unordered_map<int, int> cnt[m];

int n, kk;
int a[alph];

bool f(int k) {
	for(int i = 0; i < 3; i++)
		cnt[i].clear();
	int j = 0;
	ll hsh[3] = {0, 0, 0};
	ll pw[3] = {1, 1, 1};
	for(int i = 0; i < k-1; i++)
		for(int l = 0; l < m; l++)
			pw[l] = pw[l] * alph % mod[l];
	for(int i = 0; i + k <= n; i++) {
		while(j < i + k) {
			for(int l = 0; l < m; l++)
				hsh[l] = (hsh[l] * alph % mod[l] + a[j]) % mod[l];
			j++;
		}
		int mini = INT_MAX;
		for(int l = 0; l < m; l++) {
			mini = min(mini, ++cnt[l][hsh[l]]);
			hsh[l] = ((hsh[l] - a[i] * pw[l]) % mod[l] + mod[l]) % mod[l];
		}
		if(mini >= kk)
			return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &kk);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]),a[i]++;
//    f(4);
	int lo = 2, hi = n + 1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(f(mid))
			lo = mid + 1;
		else
			hi = mid;
	}
	printf("%d\n", lo - 1);
}
