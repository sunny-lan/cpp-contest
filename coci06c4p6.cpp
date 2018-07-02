#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 200000
#define MAXB 450

int dd[MAXB];
vector<pair<pii, int>> ppl[MAXB];

struct qry {
	char op;
	int x, y;
};

qry q[MAXN];

int a[MAXN], b[MAXN];

int main() {
    memset(dd, 0x8f, sizeof dd);
	int n;
	scanf("%d", &n);
	vector<int>  car;
	for(int i = 0; i < n; i++) {
		scanf(" %c", &q[i].op);
		if(q[i].op == 'D')
			scanf("%d %d", &q[i].x, &q[i].y), car.push_back(q[i].y);
		else
			scanf("%d", &q[i].x), q[i].x--;
	}
	sort(car.begin(), car.end());
	car.resize(unique(car.begin(), car.end()) - car.begin());
	unordered_map<int, int> ord;
	for(int i = 0; i < car.size(); i++)
		ord[car[i]] = i;
	int bs = (int)sqrt(car.size());
	int blks = (car.size() + bs - 1) / bs;
	int idx = 0;
	for(int i = 0; i < n; i++) {
		if(q[i].op == 'D') {
			a[idx] = q[i].x, b[idx] = ord[ q[i].y];
			dd[b[idx] / bs]=max(a[idx],dd[b[idx] / bs] );
			ppl[b[idx] / bs].push_back({{b[idx], a[idx]}, idx});
			idx++;
		} else {
			int r = q[i].x;
			pair<pii, int> mini = {{INT_MAX, INT_MAX}, INT_MAX};
			for(auto k : ppl[b[r] / bs])
				if(k.s!=r && k.f.f >= b[r] && k.f.s >= a[r] )
					mini = min(mini, k);
			if(mini.s != INT_MAX) {
				printf("%d\n", mini.s+1);
				goto outer;
			}
			for(int j = (b[r] / bs) + 1; j < blks; j++)
			{
				if(dd[j]>=a[i]) {
					pair<pii, int> mini = {{INT_MAX, INT_MAX}, INT_MAX};
					for(auto k : ppl[j])
						if(k.s!=r && k.f.f >= b[r] && k.f.s >= a[r])
							mini = min(mini, k);
					if(mini.s != INT_MAX) {
						printf("%d\n", mini.s+1);
						goto outer;
					}
				}
			}
			printf("NE\n");
		outer:
			continue;
		}
	}
}
