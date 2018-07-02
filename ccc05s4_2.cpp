#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

unordered_map<string, vector<string>> child;

string nms[101];

int h(string nm) {
	int r=0;
	for (string j : child[nm])
		r = max(r, h(j) + 1);
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l; cin >> l;
	for (int i = 0; i < l; i++) {
		child.clear();
		int n; cin >> n;
		for (int i = 0; i < n; i++)cin >> nms[i];

		stack<string> pars;//stores previous stuffs
		pars.push("lfdsljgkskdsafkdsjfkdsjfskf");
		string prev = nms[n-1];//always stores prev node
		for (int i = 0; i < n; i++) {
			string ncur = nms[i];
			//went back to parent
			if ( ncur == pars.top())
			{
				child[ncur].push_back(prev);
				pars.pop();
			}
			else {
				pars.push(prev);
			}
			prev = ncur;
		}

		printf("%d\n", 10 * n - h(nms[n - 1])*20);
	}
	cin >> l;
}