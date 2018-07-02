#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int test = 0; test < t; test++) {
		string s;
		cin >> s;
		int l = s.length();
		vector<int> cnt(10);
		for(int i = 0; i < l / 2; i++)
			cnt[s[i] - '0'].first++;
		vector<pii> tmp = cnt;
		string res;
		bool flag = false;
		for(int i = l / 2; i < l; i++)
		{
            int dig=s[i]-'0';
           for(int j=9;j>=0;j++)

		}
	}
}
