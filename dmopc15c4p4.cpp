#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
//NOTE: SCAN DOES NOT WORK WITH NEGATIVE NUMBERS

int prefix[100001];

vector<int> _num[2010];
vector<int> *num = _num + 1005;

int main() {
	int n, k, q; scanf("%d %d %d", &n, &k, &q);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		prefix[i + 1] = x + prefix[i];
		num[x].push_back(i);
	}

	for (int i = 0; i < q; i++) {
		int a, b, x, y; scanf("%d %d %d %d", &a, &b, &x, &y);
		x--, y--;
		if (prefix[y + 1] - prefix[x] <= k) {
			printf("No\n");
			continue;
		}

		auto xloca = lower_bound(num[a].begin(), num[a].end(), x);
		auto yloca = upper_bound(num[a].begin(), num[a].end(), y+1);
		if (yloca - xloca <= 0) {
			printf("No\n");
			continue;
		}

		auto xlocb = lower_bound(num[b].begin(), num[b].end(), x);
		auto ylocb = upper_bound(num[b].begin(), num[b].end(), y+1);
		if (ylocb - xlocb <= 0) {
			printf("No\n");
			continue;
		}

		printf("Yes\n");
	}
}