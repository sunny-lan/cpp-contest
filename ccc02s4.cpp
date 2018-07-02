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

#define MAXN 110

string ppl[MAXN];
int bad[MAXN];

int dp[MAXN];
int ptr[MAXN];

int main() {
	memset(dp, 0x3f, sizeof dp);

	int m, q; cin >> m >> q;
	for (int i = 0; i < q; i++)
		cin >> ppl[i] >> bad[i];

	dp[0] = 0;
	ptr[0] = -1;

	for (int i = 0; i < q; i++) {
		int slow = -1;
		for (int j = i; j < i + m; j++) {
			slow = max(slow, bad[j]);
			int alt = dp[i] + slow;
			if (alt < dp[j + 1])
			{
				dp[j + 1] = alt;
				ptr[j + 1] = i;
			}
		}
	}

	int currPtr = q;
	vector<vector<string>> cust;
	while (currPtr != -1) {
		vector<string> cust2;
		for (int i = ptr[currPtr]; i < currPtr; i++) {
			cust2.push_back(ppl[i]);
		}
		currPtr = ptr[currPtr];
		cust.push_back(cust2);
	}

	cout << "Total Time: " << dp[q];
	for (int i = cust.size() - 1; i >= 0;i--) {
		for (auto d : cust[i]) {
			cout << d << " ";
		}
		cout << endl;
	}

	cin >> q;
}