#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 7
int v[MAXN];

int main() {
	int g; scan(g);
	for (int t = 0; t < g; t++) {
		int n; scan(n);
		for (int i = 0; i < n; i++)
			scan(v[i]);

		int ph, mh; scan(ph); scan(mh);
		for (int s = 0; s < 1 << n; s++) {
			int a=0, b=0;
			for (int i = 0; i < n; i++) {
				if (s >> i & 1)
					a += v[i];
				else
					b += v[i];
			}
			if (a >= ph && b >= mh) {
				cout << "LETHAL" << endl;
				goto end;
			}
		}
		cout << "NOT LETHAL" << endl;
	end:
		continue;
	}
	cin >> g;
}