#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100010

typedef long ll;

ll score[MAXN];
ll sScore[MAXN];

ll n;

unordered_map<ll, ll> ord;

ll bit[MAXN];

void update(ll p, ll v) {
	ll curr = p;
	while (curr < MAXN) {
		bit[curr] += v;
		curr += curr & -curr;
	}
}

ll query(ll p) {
	ll res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

ll rounded_division(ll a, ll b) {
	ll q = a / b;
	ll r = a % b;
	return q + r / (b / 2 + b % 2);
}

int main() {
	scan(n);

	for (ll i = 0; i < n; i++) {
		scan(score[i]);
		score[i] = -score[i];
		sScore[i] = score[i];
	}

	sort(sScore, sScore + n);

	ll j = 0;
	for (ll i = 0; i < n; i++)
		if (ord.find(sScore[i]) == ord.end()) {
			j++;
			ord[sScore[i]] = j;
			//cout << sScore[i] << " => " << j << endl;
		}


	ll total = 0;
	for (ll i = 0; i < n; i++) {
		ll idx = ord[score[i]];
		ll res = query(idx-1) + 1;
		total += res;
		update(idx, 1);
	}

	//for (int i = 1; i <= n; i++)
		//cout << query(i) << endl;

	double output = (double)total / (double)n;
	printf("%.2lf", output);
}