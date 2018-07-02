#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100002

int c[MAXN];
int dp[MAXN];
int src[MAXN];

int dist(int a, int b) {
	return (c[a] - c[b])*(c[a] - c[b]);
}

int main() {
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	dp[0] = h;
	src[0] = 0;

	

	cout << dp[n-1] << endl;

	cin >> n;

	return 0;
}