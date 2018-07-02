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
using namespace std;

#define memeset memset
#define INF(a) (a==-1?INT_MAX:a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	int a, b; cin >> a >> b;
	int c = b - a;
	if (c > 0 && c <= 20)
		cout << "You are speeding and your fine is $100.\n";
	else if (c > 20 && c <= 30)
		cout << "You are speeding and your fine is $270.\n";
	else if (c > 30)
		cout << "You are speeding and your fine is $500.\n";
	else
		cout << "Congratulations, you are within the speed limit!\n";
}