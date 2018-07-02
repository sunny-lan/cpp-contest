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

int l[3], h[3];

int main() {
	for (int i = 0; i < 3; i++) {
		scan(l[i]); scan(h[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int r1 = 0; r1 < 2; r1++) {
			swap(l[i], h[i]);
			for (int j = 0; j < 3; j++)if (j != i)
				for (int r1 = 0; r1 < 2; r1++) {
					swap(l[j], h[j]);
					for (int k = 0; k < 3; k++)
						if (k != i && k != j)
							for (int r1 = 0; r1 < 2; r1++) {
								swap(l[k], h[k]);
								if (l[i] == l[j] && l[j] == l[k])
									if (l[i] == h[i] + h[j] + h[k])
									{
										printf("YES");
										return 0;
									}
								if (h[i] == h[j] && h[j] == h[k])
									if (h[i] == l[i] + l[j] + l[k])
									{
										printf("YES");
										return 0;
									}
								{
									int nl = l[i] - l[j];
									int nh = h[j];
									if (nl == l[k] && nh == h[k])
										if (h[j] + h[i] == l[i])
										{
											printf("YES");
											return 0;
										}
								}
								{
									int nl = l[i];
									int nh = h[j] - h[i];
									if (nl == l[k] && nh == h[k])if (l[i] + l[j] == h[j]) {

										printf("YES");
										return 0;
									}
								}
							}
				}
		}
	}
	printf("NO");
}