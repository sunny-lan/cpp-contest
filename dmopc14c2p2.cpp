#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	int n; cin >> n;
	string s; ws(cin); getline(cin, s);
	vector<int> logs;
	int con = 0;
	for (int i = 0; i<n; i++) {
		if (s[i] == 'O')
			con++;
		else {
			if (con>0)
				logs.push_back(con);
			con = 0;
		}
	}
	if (con>0)
		logs.push_back(con);
	cout << logs.size() << endl;
	for (int log : logs) {
		for (int i = 0; i<log; i++)
			cout << "O";
		cout << endl;
	}
	return 0;
}