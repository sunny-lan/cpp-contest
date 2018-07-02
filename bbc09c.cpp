#ifdef DMOJ

#include <bits/stdc++.h>

#else

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

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 200000

vector<int> adj[MAXN];

bool col[MAXN];

vector<int> path;
void go(int i) {
	path.push_back(i);
	col[i] = !col[i];
}

void f(int i, int j) {
	for(int neigh:adj[i])
		if (neigh != j)
		{
			go(neigh);
			f(neigh, i);
			go(i);
		}
	if (!col[i]) {
		if (j == -1) {
			path.pop_back();
		}
		else {
			go(j);
			go(i);
		}
	}
}



int main() {
	int n; scan(n);
	cout << n << endl;
	bool d=true;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (x == 1)col[i] = true;
		d &= col[i];
		cout << x << endl;
	}
	if (d)printf("1\n"), exit(0);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		cout << a << " " << b << endl;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	f(0, -1);
	printf("1");
	for (int i : path)
		printf(" %d", i + 1);
	printf("\n");
	cin >> n;
}