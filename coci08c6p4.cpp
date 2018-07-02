#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000


int main() {
	int n;
	scanf("%d", &n);
	vector<int> z, o;
	int fg = 0, sl = 0;
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if(a % 3 == 0)
			z.push_back(a);
		else {
			o.push_back(a);
			if(a % 3 == 1)
				fg++;
			else
				sl++;
		}
	}
	vector<int> mid;
	if(z.size() > 0) {
		mid.push_back(z[0]);
		for(int i = 1; i < z.size(); i++) {
			if(o.empty()) {
				printf("impossible\n");
				return 0;
			}
			mid.push_back(o.back());
			o.pop_back();
			mid.push_back(z[i]);
		}
	}
	if(mid.empty() && sl > 0 && fg > 0) {
		printf("impossible\n");
		return 0;
	}

	for(int i : o)
		if(i % 3 == 1)
			printf("%d ", i);
	for(int i : mid)
		printf("%d ", i);
	for(int i : o)
		if(i % 3 == 2)
			printf("%d ", i);
}
