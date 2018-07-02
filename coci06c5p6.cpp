#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int m = 3, alph = 27;
int mod[m] = {15001141,	15000067,	15002957};
bitset<15002957> chz[m];

int n;
int a[200000];

bool f(int k) {
	for(int i = 0; i < m; i++)
		chz[i].reset();
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
		bool v=true;
		for(int l = 0; l < m; l++) {
			if(!chz[l][hsh[l]])
                v=false;
            chz[l][hsh[l]]=1;
			hsh[l] = ((hsh[l] - a[i] * pw[l]) % mod[l] + mod[l]) % mod[l];
		}
		if(v)
            return true;
	}
	return false;
}

int mp[26];

int main() {
    srand(time(0));
    for(int i=0;i<26;i++)
        mp[i]=i+1;
    random_shuffle(mp, mp+26);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >>n>>s;
	for(int i = 0; i < n; i++)
		a[i]=mp[s[i]-'a'];
	int lo = 1, hi = n + 1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(f(mid))
			lo = mid + 1;
		else
			hi = mid;
	}
	printf("%d\n", lo - 1);
}
