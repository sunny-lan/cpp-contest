#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100001

pii p[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &p[i].s, &p[i].f);
	sort(p, p + n);
	vector<pair<pii, int>> tre;
	vector<int> res;
	for(int i = 0; i < n; i++) {
		int mini = INT_MAX, bst = -1;
		for(int j = 0; j < tre.size(); j++) {
			int alt = abs(tre[j].f.s - p[i].s);
			if(alt <= abs(tre[j].f.f - p[i].f)) {
				if(alt < mini)
					mini = alt, bst = j;
			}
		}
		if(bst != -1)
			tre.erase(tre.begin() + bst),
			bst = tre[bst].s;
		else
			bst = tre.size();

		res.push_back(bst);
		tre.push_back({p[i], bst});
	}
	printf("%d\n", tre.size());
	for(int i : res)
		printf("%d\n", i + 1);
}
