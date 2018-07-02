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
	int n1;
	cin >> n1;
	string s;
	ws(cin);
	getline(cin, s);
	int n2;
	cin >> n2;
	if (s == "Infront")
		cout << n1 - n2 << endl;
	else
		cout << n1 + n2 << endl;
	cin >> n1;
}