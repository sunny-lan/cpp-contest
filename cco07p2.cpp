#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

vector<int> lst[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int v[6];
		for(int j = 0; j < 6; j++)
			scanf("%d", &v[j]);
		for(int j = 0; j < 6; j++)
			lst[i].push_back(INT_MAX);
		for(int j = 0; j < 6; j++)
		{
			vector<int> s;
			for(int k = 0; k < 6; k++)
				s.push_back(v[(j + k) % 6]);
			if(s < lst[i])
				lst[i] = s;
			s.clear();
			for(int k = 5; k >= 0; k--)
				s.push_back(v[(j + k) % 6]);
			if(s < lst[i])
				lst[i] = s;
		}
	}
	sort(lst, lst + n);
	if(unique(lst, lst + n) - lst < n)
		printf("Twin snowflakes found.");
	else
		printf("No two snowflakes are alike.");
}
