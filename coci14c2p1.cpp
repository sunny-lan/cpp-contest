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

int map[10];

string stuff[10] = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

int main() {
	for (int i = 1; i < 10; i++)
	{
		int b; cin >> b;
		map[b] = i;
	}

	ws(cin);

	string s; getline(cin, s);
	int n = s.length();
	int last = -1;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		int idx;
		int idx2;
		for (int j = 0; j < 10; j++) {
			if ((idx2=stuff[j].find(c)) != string::npos) {
				idx = j;
				break;
			}
		}
		if (idx == last)
			cout << "#";
		for (int j = 0; j <= idx2; j++)
			cout << map[idx];
		last = idx;
	}
	cout << endl;
	cin >> n;
}