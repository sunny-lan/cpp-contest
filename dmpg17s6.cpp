#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

bool open(char c) {
	return c == '{' || c == '(' || c == '[';
}

char op(char c) {
	if(c == '{')
		return '}';
	if(c == '[')
		return ']';
	if(c == '(')
		return ')';
}

char nxt(char c) {
	if(c == '{')
		return '[';
	if(c == '[')
		return '(';
	if(c == '(')
		return '{';
}

char alt(char a, char b) {
	if(a == '{' && b == ']')
		return '(';
	if(a == '{' && b == ')')
		return '[';
	if(a == '[' && b == '}')
		return '(';
	if(a == '[' && b == ')')
		return '{';
	if(a == '(' && b == '}')
		return '[';
	if(a == '(' && b == ']')
		return '{';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s, out;
	cin >> n >> k >> s;
	out = s;
	stack<int> locs;
	vector<pii> match;
	for(int i = 0; i < n; i++) {
		if(open(s[i])) {
			locs.push(i);
		} else {
			if(locs.empty()) {
				cout << "impossible" << endl;
				return 0;
			} else {
				match.push_back({locs.top(), i});
				locs.pop();
			}
		}
	}
	if(!locs.empty()) {
		cout << "impossible" << endl;
		return 0;
	}
	for(pii p : match) {
		if(op(s[p.f]) != s[p.s]) {
			out[p.s] = op(s[p.f]);
			if(--k < 0) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	for(pii p : match) {
		if(k < 2)
			break;
		if(op(s[p.f]) == s[p.s]) {
			out[p.f] = nxt(s[p.f]);
			out[p.s] = op(out[p.f]);
			k -= 2;
		}
	}
	for(pii p : match) {
		if(k == 0)
			break;
		if(op(s[p.f]) != s[p.s]) {
			out[p.f] = alt(s[p.f], s[p.s]);
			out[p.s] = op(out[p.f]);
			k--;
		}
	}
	if(k > 0) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << out << endl;
}
