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

#define MAXN 1000000
#define MAXB 22

int p[MAXB][MAXN];
int ptr[MAXN];
char v[MAXN];
int h[MAXN];

int curr = 0;
int cidx = 0;

void Init() {
	memset(p, -1, sizeof p);
}

void TypeLetter(char L) {
	int nidx = cidx + 1,
		ncurr = curr + 1;

	int prevptr = ptr[curr];
	v[nidx] = L;
	h[nidx] = h[prevptr] + 1;
	ptr[ncurr] = nidx;

	int i = prevptr, lvl = 0;
	while (i != -1) {
		p[lvl][nidx] = i;
		i = p[lvl][i];
		lvl++;
	}

	curr = ncurr;
	cidx = nidx;
}

void UndoCommands(int U) {
	int ncurr = curr + 1;
	ptr[ncurr] = ptr[curr - U];
	curr = ncurr;
}

char GetLetter(int P) {
	P++;
	int i = ptr[curr];
	int lvl = 22,
		cbs = 1 << lvl;
	while (h[i] != P) {
		while (h[i] - P < cbs)
			lvl--, cbs >>= 1;
		i = p[lvl][i];
	}
	return v[i];
}


int main() {
	Init();
	while (true) {
		int op; scan(op);
		if (op == 1) {
			char l; scanf(" %c", &l);
			TypeLetter(l);
		}
		else if (op == 2) {
			int u; scan(u);
			UndoCommands(u);
		}
		else {
			int p; scan(p);
			printf("%c\n", GetLetter(p));
		}
	}
}