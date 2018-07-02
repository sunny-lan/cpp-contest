#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000001

vector<int> factors[MAXN];


int main() {
	vector<int> primes;
	for (int i = 2; i <= 200000; i++)
	{
		for (int j = 2; j*j <= i; j++)
			if (i%j == 0)
				goto outer;
		primes.push_back(i);
	outer:continue;
	}

	int  n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		int idx = -1;
		for (int div = 0; a > 1 && primes[div] <= a; div++)
			while (a > 1 && primes[div] <= a && a % primes[div] == 0) {
				a /= primes[div];
				factors[i].push_back(div);
			}
	}

	int res = 0;
	int l = 0;
	unordered_map<int, set<pii>> cancer;

	for (int r = 0; r < n; r++) {
		for (int v : factors[r])
			cancer[v].insert({ v.second, r });
		while (l < r) {
			if (cancer.size() <= k) {
				int tot = 0;
				for (pii v : factors[l])
					tot += cancer[v.first].begin()->first;
				if (tot >= k)
					break;
			}
			for (pii v : factors[l]) {
				cancer[v.first].erase({ v.second, l });
				if (cancer[v.first].empty())
					cancer.erase(v.first);
			}
		}
		if (cancer.size() <= k) {
			int tot = 0;
			for (pii v : factors[l])
				tot += cancer[v.first].begin()->first;
			if (tot == k)
				res += r - l;
		}
	}

	printf("%d\n", res);
	cin >> n;
}