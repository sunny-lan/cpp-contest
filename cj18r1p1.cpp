#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(string p) {
	ll res = 0, pwr = 1;
	for(int i = 0; i < p.length(); i++) {
		if(p[i] == 'C')
			pwr *= 2;
		else
			res += pwr;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++) {
		cout << "Case #" << test << ": ";
		int d;
		string p;
		cin >> d >> p;
		int cnt = 0;
		while(calc(p) > d) {
			for(int i = p.length() - 2; i >= 0; i--)
				if(p[i] == 'C' && p[i + 1] == 'S') {
					swap(p[i], p[i + 1]);
					goto nxt;
				}

			cout << "IMPOSSIBLE" << endl;
			goto outer;
		nxt:
			cnt++;
		}
		cout << cnt << endl;
	outer:
		continue;
	}
}
