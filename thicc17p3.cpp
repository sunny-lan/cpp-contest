#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_map>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000000

vector<pair<int, int>> days[MAXN];

bool pred(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
	{
		int j; scan(j);
		days[i].push_back({ 0,j });
	}

	int q; scan(q);
	int day = 1;
	for (int i = 0; i < q; i++) {
		char op; int x, y; scanf(" %c %d %d", &op, &x, &y);
		x--;
		if (op == 'C')
		{
			days[x].push_back({ day, y });
			day++;
		}
		else {
			pair<int, int> tmp = { y ,0 };
			int idx = upper_bound(days[x].begin(), days[x].end(),tmp , pred) - days[x].begin();
			printf("%d\n", days[x][idx - 1].second);
		}
	}
}