#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500

int gs[MAXN];
int k[MAXN];

int main() {
	int g; cin >> g;
	int p = 0;
	for (int i = 0; i < g; i++) {
		cin >> gs[i];
		p += gs[i] + 1;
	}

	for (int i = 0; i < g; i++)
		cin >> k[i];

	cout << p << endl;

	for (int i = 0; i < g; i++) {
		for (int j = 0; j < gs[i]; j++)
			cout << " Princess " << endl;
		cout << "poo" << endl;
	}

	for (int i = 0; i < g; i++)
		cout << k[i] <<endl;

	cin >> g;
}