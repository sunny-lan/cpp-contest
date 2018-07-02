#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector<string> stuff;

int main() {
	int n; cin >> n;
	ws(cin);
	for (int i = 0; i < n; i++) {
		string s; getline(cin, s);
		stuff.push_back(s);
	}

	sort(stuff.begin(), stuff.end());

	while (!stuff.empty()) {
		string s = stuff.front();
		cout << s;
		stuff.erase(stuff.begin());
		if (stuff.empty() || stuff.front()[0] != s[0])
			cout << endl;
		else
			cout << ", ";
	}
	cin >> n;
}