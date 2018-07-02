#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	set<int> z, o;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0')
			z.insert(i);
		else
			o.insert(i);
	}

	vector<vector<int>> res;

	while(!z.empty()) {
		int zloc = *z.begin();
		z.erase(zloc);
		vector<int> locs;
		locs.push_back(zloc);
		while(true) {
			auto no = o.upper_bound(zloc);
			if(no == o.end())
				break;
			auto nz = z.upper_bound(*no);
			if(nz == z.end())
				break;
            zloc=*nz;

			locs.push_back(*no), locs.push_back(zloc);

			o.erase(no), z.erase(nz);
		}
		res.push_back(locs);
	}

	if(!o.empty()) {
		printf("-1");
		return 0;
	}

	printf("%d\n", res.size());
	for(auto locs : res) {
		printf("%d", locs.size());
		for(int l : locs)
			printf(" %d", l + 1);
		printf("\n");
	}
}
