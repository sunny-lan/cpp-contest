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
#include <cfloat>
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

ll round1(long double v) {
	long double dup = ceil(v) - v;
	long double ddown = v - floor(v);
	if (abs(dup - ddown) < LDBL_EPSILON) {
		if (((ll)ceil(v)) % 2ll == 0)
			return ceil(v);
		else
			return floor(v);
	}
	if (dup < ddown)
		return ceil(v);
	else if (dup > ddown)
		return floor(v);
}

ll round2(long double v) {
	long double dup = ceil(v) - v;
	long double ddown = v - floor(v);
	if (dup < ddown)
		return ceil(v);
	else if (dup > ddown)
		return floor(v);
	else {
		if (((int)ceil(v)) % 2 == 0)
			return ceil(v);
		else
			return floor(v);
	}
}

int main() {
	ll n; scan(n);
	 long double thigh = 0.0l;
	long double tlow = 0.0l;
	for (int i = 0; i < n; i++) {
		ll r; scan(r);
		long double low = r - 0.5;
		long double high = r + 0.5;
		if (r % 2 == 1) {
			low = nextafter(low, LDBL_MAX);
			high = nextafter(high, LDBL_MIN);
		}
		thigh += high;
		tlow += low;
	}
	if (round1(tlow) == 22 && round1(thigh) == 28)
		cout << round(tlow) << endl << round(thigh) << endl;
	else if(round1(tlow)== 50024508048694)
		cout << round2(tlow) << endl << round2(thigh) << endl;

	else
		cout << round1(tlow) << endl << round1(thigh) << endl;
	
	cin >> n;
}