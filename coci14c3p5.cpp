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

#define MAXN 300010

int n, bs;

int parent[MAXN];
int blockparent[MAXN];
int ptr[MAXN];
int h[MAXN];

int nextBlock(int x) {
	int initblock = x / bs;
	while (true) {
		int currblock = x / bs;
		if (currblock < initblock || x == 0)
			return x;
		x = parent[x];
	}
}

int main() {
	memset(parent, -1, sizeof parent);

	scan(n);
	bs = sqrt(n);

	for (int i = 1; i <= n; i++) {
		char op; int v; scanf(" %c %d", &op, &v);
		if (op == 'a')
		{
			ptr[i] = i;
			parent[i] = ptr[v];
			h[i] = h[parent[i]] + 1;
			blockparent[i] = nextBlock(i);
		}
		else if (op == 'b') {
			ptr[i] = parent[ptr[v]];
			printf("%d\n", ptr[v]);
		}
		else {
			int w; scan(w);
			ptr[i] = ptr[v];
			int lasta, a = lasta = ptr[v],
				lastb, b = lastb = ptr[w];
			while (a != b) {
				if (h[b] > h[a]) lastb = b, b = blockparent[b];
				else if (a == b)break;
				else lasta = a, a = blockparent[a];
			}
			if (lasta / bs == lastb / bs) {
				a = lasta, b = lastb;
				while (a != b) {
					if (h[b] > h[a])b = parent[b];
					else if (a == b)break;
					else a = parent[a];
				}
			}

			printf("%d\n", h[a]);
		}
	}
}