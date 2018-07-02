#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100

int val[MAXN];

int main() {
	int n; cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		for (int j = 0; j <= i; j++) {
			bool flag = true;
			for (int k = j; k < i; k++)
				if (abs(val[k] - val[k + 1]) > 2)
				{
					flag = false;
					break;
				}
			if (flag)
				maxi = max(maxi, i - j+1);
		}
	}
	cout << maxi << endl;
}