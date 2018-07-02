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

#define MAXN 100010

bool cust[MAXN];

int main() {
	ios::sync_with_stdio(false);
	memset(cust, false, sizeof cust);
	int n, t; scanf("%d %d", &n, &t);
	int a = 0, b = 0;
	char s; scanf("%c", &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &s);
		if(s=='|')
		cust[i] = true;
		else cust[i] = false;
		if (cust[i])a++;
		else b++;
	}

	for (int i = 0; i < t; i++) {
		int k; scanf("%d", &k); k--;
		if (cust[k])a--,b++;
		else b--,a++;
		cust[k] = !cust[k];
		if (cust[0])printf("1\n");
		else printf("%d\n", a * 3 + b);
	}
}