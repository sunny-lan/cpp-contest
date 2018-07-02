#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	string msg; getline(cin, msg);
	for (char c : msg) {
		if (c >= '0' && c <= '9') {
			int val = c - '0' - 1;
			if (val < 0)val = '9'-'0';
			cout << (char)('A' + val);
		}

		if (c >= 'A' && c <= 'J') {
			int val = c - 'A' ;
			//if (val < 0)val = 'T'-'K';
			cout << (char)('K' + val - 1);
		}

		if (c >= 'K' && c <= 'P') {
			int val = c - 'K' ;
			//if (val < 0)val = 'Z' - 'U';
			cout << (char)('U' + val - 1);
		}
	}
	cout << endl;
	getline(cin, msg);
}