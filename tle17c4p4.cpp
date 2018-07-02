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

#define MAXN 20000

double x[MAXN];
double y[MAXN];

bool _c[4010];
bool *c = _c + 2005;

int main() {
	int n; double k; scanf("%d %lf", &n, &k);
	for (int i = 0; i < n; i++) {
		int cx, cy;
		scanf("%d %d", &cx, &cy);
		x[i] = cx, y[i] = cy;
		c[cy] = true;
	}

	double h = sqrt(k*k - (k/2.0)*(k/2.0));

	int maxi = 0;
	for (int _cy = -2000; _cy <= 2000; _cy++)if (c[_cy]) {
		double cy = _cy;
		//upper sweep
		vector<double> stPts, edPts;
		for (int i = 0; i < n; i++)
		{
			if (y[i] > cy + h || y[i] < cy)continue;
			double deltY = y[i] - cy;
			double sol = k*(h - deltY) / (2.0 * h);
			stPts.push_back(x[i] - sol);
			edPts.push_back(x[i] + sol);
		}
		sort(stPts.begin(), stPts.end());
		sort(edPts.begin(), edPts.end());
		int a = 0, b = 0;
		int cnt = 0;
		for (int i = 0; i < stPts.size();i++) {
			double cx = stPts[i];
			while (a < stPts.size() && stPts[a] <= cx)
				a++, cnt++;
			while (b < edPts.size() && edPts[b] < cx)
				b++, cnt--;
			maxi = max(maxi, cnt);
		}

		//lower sweep
		stPts = vector<double>(), edPts = vector<double>();
		for (int i = 0; i < n; i++)
		{
			if (y[i] < cy - h || y[i] > cy)continue;
			double deltY = y[i] - cy;
			double sol = k*(h + deltY) / (2.0 * h);
			stPts.push_back(x[i] - sol);
			edPts.push_back(x[i] + sol);
		}
		sort(stPts.begin(), stPts.end());
		sort(edPts.begin(), edPts.end());
		a = 0, b = 0;
		cnt = 0;
		for (int i = 0; i < stPts.size(); i++) {
			double cx = stPts[i];
			while (a < stPts.size() && stPts[a] <= cx)
				a++, cnt++;
			while (b < edPts.size() && edPts[b] < cx)
				b++, cnt--;
			maxi = max(maxi, cnt);
		}
	}

	printf("%d\n", maxi);
	cin >> n;
}