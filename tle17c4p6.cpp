#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector<double> locs;

double f(double x) {
	double tot = 0;
	for (int a:locs) 
		tot -= 3.0 * (a - x)*abs(a - x);
	return tot;
}

int main() {
	int n; scan(n);
	double maxi = -INT_MAX;
	double mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		double xx; scanf("%lf", &xx);
		locs.push_back(xx);
		maxi = max(maxi, xx);
		mini = min(mini, xx);
		double hi = maxi;
		double lo = mini;
		double mid;
		for (int j = 0; j < 100; j++) {
			 mid = (hi + lo) / 2.0;
			double res = f(mid);
			if (res < 0.0)
				lo = mid;
			else if (res > 0.0)
				hi = mid;
			else
				break;
		}
		printf("%lf\n", mid);
	}
	cin >> n;
}