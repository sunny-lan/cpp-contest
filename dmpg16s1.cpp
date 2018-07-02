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
#include <set>
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

#define MAXN 100000

int x[MAXN];
int f[MAXN];

multiset<int> xs;
multiset<int> fs;

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(f[i]);
		fs.insert(f[i]);
	}
	for (int i = 0; i < n; i++) {
		scan(x[i]);
		xs.insert(x[i]);
	}

	int pt = 0;
	for (int i = 0; i < n; i++) {
		auto loc = fs.upper_bound(x[i]);
		if (loc != fs.end()) {
			pt++;
			fs.erase(loc);
		}
	}
	cout << pt << endl;
	
	 pt = 0;
	for (int i = 0; i < n; i++) {
		auto loc = xs.upper_bound(f[i]);
		if (loc != xs.end()) {
			pt++;
			xs.erase(loc);
		}
	}
	cout << pt << endl;
}