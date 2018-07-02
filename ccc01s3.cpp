#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

vector<int> adj[26];

pii edge[900];
pii blk;

bool v[26];
void f(int i) {
	if (v[i])return;
	v[i] = true;
	for (int j : adj[i])
	{
		if (i == blk.first && j == blk.second)continue;
		if (j == blk.first && i == blk.second)continue;
		f(j);
	}
}

int main() {
	int idx = 0;
	while (true) {
		string s; cin >> s;
		if (s == "**")break;
		int u = s[0] - 'A',
			v = s[1] - 'A';
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge[idx++] = { u,v };
	}

	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		blk = edge[i];
		memset(v, false, sizeof v);
		f(0);
		if (!v[1]) {
			cnt++;
			printf("%c%c\n", (char)(blk.first + 'A'), (char)(blk.second + 'A'));
		}
	}

	printf("There are %d disconnecting roads.\n", cnt);
	cin >> idx;
}