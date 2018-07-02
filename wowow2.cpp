#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MAXN 1000005

int numRatings;
int tree[MAXN];
int bitmask_origin;

vector<pair<int, int>> operations;
char code;
int code2;
int x, r, k;
vector<int> ratings;

int oldR;
unordered_map<int, int> ratingsCompressed, ratingsDecompressed, idToRating, ratingToId;
int n;

int cnt;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &code);
		if (code == 'N') {
			scanf("%d%d", &x, &r);
			operations.push_back(make_pair(0, r));
			idToRating[x] = r; 
			ratingToId[r] = x;
			ratings.push_back(r);
		}
		else if (code == 'M') {
			scanf("%d%d", &x, &r);
			operations.push_back(make_pair(1, idToRating[x]));
			ratings.push_back(r);
			idToRating[x] = r;
			ratingToId[r] = x;
			operations.push_back(make_pair(0, r));

		}
		else if (code == 'Q') {
			scanf("%d", &k);
			operations.push_back(make_pair(2, k));
		}
	}

	sort(ratings.begin(), ratings.end());
	reverse(ratings.begin(), ratings.end());
	numRatings = ratings.size();
	for (int i = 0; i < numRatings; i++) {
		ratingsDecompressed[i + 1] = ratings[i];
		ratingsCompressed[ratings[i]] = i + 1;
	}
	for (int i = 0; i < operations.size(); i++) {
		code2 = operations[i].first;
		if (code2 == 0) {
			r = ratingsCompressed[operations[i].second];
			//increment bit
			for (int j = r; j <= n; j += j&-j)
				tree[j] += 1;
		}
		else if (code2 == 1) {
			r = ratingsCompressed[operations[i].second];
			//decrement bit
			for (int j = r; j <= n; j += j&-j)
				tree[j] -= 1;
		}
		else if (code2 == 2) {
			k = operations[i].second;

			r = 0;
			cnt = 0;

			for (int i = 20; i >= 0; i--) {
				r += (1 << i);
				if (r > n || cnt + tree[r] >= k)
					r -= (1 << i);
				else
					cnt += tree[r];
			}

			x = ratingToId[ratingsDecompressed[r + 1]];
			//cout << "looking for " << k << "th person - rating=" << r << ", id=" << x << endl;
			printf("%d\n", x);

		}
	}
	//cin >> k;

	return 0;
}