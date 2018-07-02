#include <bits/stdc++.h>
using namespace std;

int cnt[3];

int main() {
	string s;
	cin >> s;
	char cc = 'a';
	for(char c : s) {
		if(c != cc) {
			if(c != cc + 1)
				goto kust;
			else
				cc = c;
		}
		cnt[c - 'a']++;
	}
	if(cc != 'c')
		goto kust;
	if(cnt[0] == 0 || cnt[1] == 0)
		goto kust;
	if(cnt[2] != cnt[0] && cnt[2] != cnt[1])
		goto kust;

	printf("YES");
	return 0;
kust:
	printf("NO");
}
