#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> dig;
	for(char c : s) {
		int v = c - '0';
		if(v == 0 || v == 1)
			continue;
        if(v==4)
            dig.pb(2), dig.pb(2), dig.pb(3);
        else if(v==6)
            dig.pb(3), dig.pb(5);
        else if(v==8)
            dig.pb(2), dig.pb(2), dig.pb(2), dig.pb(7);
        else if(v==9)
            dig.pb(7), dig.pb(3), dig.pb(3),dig.pb(2);
        else
            dig.pb(v);
	}
	sort(dig.begin(), dig.end());
	reverse(dig.begin(), dig.end());
	for(int i : dig)
		printf("%d", i);
	printf("\n");
}
