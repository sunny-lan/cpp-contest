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

#define MAXN 100000
int _a[MAXN + 100];
int * a=_a+50;

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scan(a[i]);
	vector<int> step;
	for (int i = 0; i+1 < n; i++)
		if (a[i])
			a[i]=!a[i],
			a[i + 1] = !a[i + 1],
			a[i+2]=!a[i+2],
			step.push_back(i + 1);

	if (a[n - 1]) {
		if (n % 3 == 1)
		{
			step.push_back(n-1);
			a[n - 1] = !a[n - 1];
			a[n - 2] = !a[n - 2];
		}
		for (int i = n - 1; i-1 >= 0; i--)
			if (a[i])
				a[i] = !a[i],
				a[i - 1] = !a[i - 1],
				a[i - 2] = !a[i - 2],
				step.push_back(i - 1);
	}
	

	printf("%d\n", step.size());
	for (int i : step)
		printf("%d\n", i+1);
	cin >> n;
}