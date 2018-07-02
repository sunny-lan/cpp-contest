#include<iostream>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;

#define MAXN 100000

ll stations[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	ll a, b, c; scan(a); scan(b); scan(c);
	for (int i = 0; i < n; i++)
	{
		int s; scan(s);
		stations[s - 1]++;
	}
	int currStation = 0;
	int soldiers = n;

	ll total = 0;
	ll t = 0;
	ll ac = 0;
	while (soldiers > 0 && currStation < m) {
		if (stations[currStation] == 0) {
			currStation++;
			continue;
		}
		soldiers--;

		ll paraCost = (b-a)*currStation;
		ll savings = soldiers*c;
		stations[currStation]--;

		if (paraCost < savings) {
			total += b*currStation;
		}
		else {
			total += t;
			t += c;
			ac += a*currStation;
		}
	}
	total += ac;
	cout << total << endl;
	cin >> n;
}