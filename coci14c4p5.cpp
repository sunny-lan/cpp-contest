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
bool a[MAXN];
int mis[MAXN];

int main() {
	queue<int> q;
	int n; scan(n);
	for (int i = 0; i < 5; i++) {
		int p; scan(p);
		for (int j = 0; j < p; j++) {
			int k, l; scan(k); scan(l);
			k--, l--;
			adj[k].push_back(l);
			adj[l].push_back(k);
			mis[k]++, mis[l]++;
		}
	}
	for(int i=0;i<n;i++)
		q.push(i);

	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (mis[i] > 2)
		{
			mis[i] = 0;
			a[i] = !a[i];
			for (int j : adj[i]) {
				if (a[j] == a[i])
					mis[j]++,
					mis[i]++;
				else
					mis[j]--;
				if (mis[j] > 2)
					q.push(j);
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (a[i])
			printf("A");
		else
			printf("B");
	printf("\n");
	cin >> n;
}