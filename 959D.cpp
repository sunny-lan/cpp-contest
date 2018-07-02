#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 5000001
#define MAXF 320

bool pm[MAXN];
bitset<MAXF> cur,nxt,gud;

int main() {
	int n;
	scanf("%d", &n);
	int i = 0;
	int la = -1;
	for(; i < n; i++) {
		int a;
		scanf("%d", &a);
		la = a;
		int tmp = a;
		nxt.reset();
		for(int j = 2; j < MAXF; j++)
			while(tmp % j == 0)
				nxt[j] = 1,  tmp /= j;
//            cout << "a="<<a<<" cur="<<cur<<" nxt="<<nxt<<endl;
		if(tmp == 1) { //nonprime
			if((nxt & cur).count() > 0)
				break;
		} else {
			if(pm[a])
				break;
			pm[a] = 1;
		}
		cur |= nxt;
		printf("%d ", a);
	}
	if(la == -1 || i == n)
		return 0;
	for(int j = 0; j < MAXF; j++)
		pm[j] |= cur[j];
	for(int nxt = la + 1;; nxt++)
	{
		gud.reset();
		int tmp = nxt;
		for(int j = 2; j < MAXF; j++)
			while(tmp % j == 0) {
				if(pm[j])
					goto outer;
				gud[j] = 1;
				tmp /= j;
			}
		if(tmp != 1) //prime
			if(pm[nxt])
				goto outer;
		pm[nxt] = 1;
		for(int j = 0; j < MAXF; j++)
			pm[i] |= gud[i];
		printf("%d ", nxt);
		i++;
		break;
	outer:
		continue;
	}

	for(ll j = 2; j < MAXN; j++)
		if(pm[j])
			for(ll k = j * j; k < MAXN; k += j)
				pm[k] = 1;

	int idx = 2;
	for(; i < n; i++) {
		while(pm[idx])
			idx++;
		pm[idx] = 1;
		printf("%d ", idx);
	}
}
