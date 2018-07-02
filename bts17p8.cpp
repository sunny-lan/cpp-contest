#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

typedef long long ll;

#define MAXN 10000000

int tot[MAXN];

int main() {
	int n; cin >> n;
	ws(cin);
	string l; getline(cin, l);
	if (n <= 0) {
		ll curr = 0;
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			char c = l[i];
			if (c == '-')
				curr /= 10;
			else
			{
				curr *= 10;
				curr += c - '0';
			}
			tot += curr;
		}

		cout << tot << endl;
	}
	else {
		int currloc = 0;
		int currdig = 0;
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			int c = l[i];
			if (c == '-') {
				currloc--;
				if (currloc < 0)
				{
					currloc = 0;
					currdig = 0;
				}
			}
			else
			{
				int val = c - '0';
				if (val == 0)
					currloc++;
				else {
					currdig = val;
					currloc = 0;
				}
			}
			maxi = max(currloc, maxi);
			tot[currloc] += currdig;
			if (tot[currloc] > 9) {
				tot[currloc + 1] ++;
				tot[currloc] %= 10;
			}
		}

		for (int i = 0; i <= maxi+10; i++) {
			if (tot[i] > 9) {
				tot[i + 1] ++;
				tot[i] %= 10;
			}
		}

		for (int i = maxi + 10; i >=0; i--) {
			printf("%d", (int)tot[i]);
		}
		printf("\n");
	}
	
	cin >> n;
}