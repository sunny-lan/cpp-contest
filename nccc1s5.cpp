#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

string s;
int n;
int dp[40][2][2];

int f(int d, int c, int rc) {
	int od = n - d - 1;
	if (od < d) {//middle num is diff
		if (rc == c)
			return 0;//carry match
		else
			return 4000;//carry mismatch
	}
	int v = s[d] - '0';
	int ov = s[od] - '0';
	if (od == d) {// middle num is shared
		int nv = v + c;
		if (rc == 1)//next needs carry
			return max(0, 10 - nv);//number we need to increment to get carry
		else
		{
			if (nv >= 10)return 4000;//impossible to cancel carry
			else return 0;//don't need to do anything to this digit
		}
	}
	int &res = dp[d][c][rc];
	if (res != -1)return res;
	res = 4000;

	for (int inc = 0; inc < 10; inc++) {
		int nv = v + c + inc;
		if (nv - 10 >= v)break;//no point in doing anymore increments than 10
		for (int oink = 0; oink < 10; oink++) {
			//don't ask for carry
			int nov = ov + oink;
			//must satisfy requirement for carry
			if (nov / 10 == rc) {
				//must be equal
				if (nov % 10 == nv % 10) {
					res = min(res, f(d + 1, nv / 10, 0) + inc + oink);
				}
			}
			//ask for carry
			nov = ov + oink + 1;
			if (nov - 10 >= ov)break;//no point in doing anymore increments than 10
			//must satisfy requirement for carry
			if (nov / 10 == rc) {
				//must be equal
				if (nov % 10 == nv % 10) {
					res = min(res, f(d + 1, nv / 10, 1) + inc + oink);
				}
			}
		}
	}

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> s;
	reverse(s.begin(), s.end());
	n = s.length();
	int a = f(0, 0, 0);
	int b = f(0, 0, 1);
	printf("%d\n", min(a, b));
	cin >> n;
}