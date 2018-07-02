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

#define MAXN 100000

int cnt[26];

struct q { char c; int x, i; };

q ops[MAXN];

char w[MAXN];

bool pred(q a, q b) {
	/*if (a.i+a.x == b.i+b.x) {
		return b.x < a.x;
	}*/
	return a.i+a.x < b.i+b.x;
}

int cnt2[26][MAXN];

int main() {
	memeset(cnt2, -1, sizeof cnt2);
	memeset(w, 'z', sizeof w);
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		scanf(" %c %d %d", &(ops[i].c), &(ops[i].x), &(ops[i].i));
		int &alt = cnt2[ops[i].c - 'a'][ops[i].i];
		if (alt == -1)alt = ops[i].x;
		if (alt != ops[i].x) {
			cout << -1 << endl;
			return 0;
		}
	}
	sort(ops, ops + m, pred);

	int ptr = 0;
	for (int i = 0; i < m; i++) {
		q c = ops[i];
		int cidx = c.c-'a';
		if(ptr>n) {
			cout << -1 << endl;
			return 0;
		}
		while (cnt[cidx]<c.x && ptr < c.i) {
			cnt[cidx]++;
			w[ptr] = c.c;
			ptr++;
		}
		if (cnt[cidx]!=c.x) {
			cout << -1 << endl;
			return 0;
		}
	}
		
	for (int i = 0; i < n; i++) {
		cout << w[i] ;
	}
	cout << endl;
	cin >> n;
}