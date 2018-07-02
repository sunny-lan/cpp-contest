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

struct op {
	char o;
	int v;
	bool s;
};

bool lines[MAXN];

op ops[MAXN];

vector<int> direct;
char useless;
int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &(ops[i].o));
		if (ops[i].o == 'C') {
			char tmp;
			scanf(" %c", &tmp);
			if (tmp == '?') {
				direct.push_back(i);
			}
			else if (tmp == 'W') {
				scanf("%c", &useless);
				ops[i].s = false;
			}
			else {
				scanf("%c", &useless);
				ops[i].s = true;
			}
		}
		else {
			char tmp;
			scanf("%d %c", &(ops[i].v), &tmp);
			if (tmp == '?') {
				direct.push_back(i);
			}
			else if (tmp == 'W') {
				scanf("%c", &useless);
				ops[i].s = false;
			}
			else {
				scanf("%c", &useless);
				ops[i].s = true;
			}
		}
	}

	int k = direct.size();

	int mini = INT_MAX;
	int maxi = INT_MIN;

	for (int i = 0; i < 1 << k; i++) {
		for (int j = 0; j < k; j++)if ((i >> j) & 1) {
			ops[direct[j]].s = true;
		}
		else {
			ops[direct[j]].s = false;
		}

		int wcount = 0;
		for (int j = 0; j < n; j++) {
			if (ops[j].o == 'E')
				lines[j] = !(ops[j].s ^ lines[ops[j].v-1]);
			else
				lines[j] = ops[j].s;
			if (!lines[j])
				wcount++;
		}
		mini = min(mini, wcount);
		maxi = max(maxi, wcount);
	}
	cout << mini << " " << maxi << endl;
	cin >> n;
}