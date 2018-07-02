#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000
#define MAXW 100001

int w[MAXN];
int cnt[MAXW];

int main() {
	int n; scan(n);
	double mean = 0;
	for (int i = 0; i < n; i++) {
		scan(w[i]);
		cnt[w[i]]++;
		mean += w[i];
	}
	mean /= n;

	int best = 0;
	int bestcnt = 0;
	double mode = 0;
	for (int i = 0; i < MAXW; i++) {
		if (cnt[i] > best) {
			mode = i;
			bestcnt = 1;
			best = cnt[i];
		}
		else if (cnt[i] == best) {
			bestcnt++;
			mode += i;
		}
	}
	mode /= bestcnt;

	sort(w, w + n);
	double median;
	if (n % 2 == 0)
		median = (w[n >> 1] + w[(n >> 1) - 1]) >> 1;
	else
		median = w[n >> 1];

	//cout << mean << " " << mode << " " << median << endl;

	int cntMean = 0;
	int cntMode = 0;
	int cntMed = 0;
	for (int i = 0; i < n; i++) {
		if (w[i] <= mean)
			cntMean++;
		if (w[i] <= mode)
			cntMode++;
		if (w[i] <= median)
			cntMed++;
	}

	cout << min(cntMean, min(cntMode, cntMed)) << endl;
	cin >> n;
}