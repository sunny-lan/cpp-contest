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
#include <set>

#endif // DMOJ
using namespace std;

#ifdef DMOJ
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// avail functions:
// find_by_order(x)
//  - 0 indexed
//  - returns set.end() if x>=set.size()
// order_of_key(x)
//  - returns index of smallest key that is greater than or equal to x
//  - returns set.size() if x is greater than biggest elem in set
#else
#include <set>

template <typename T>
using ordered_set = set<T>;

template <typename T>
auto findKth(ordered_set<T> s, int k) {
	if (k >= s.size())return s.end();
	return next(s.begin(), k);
}
#endif // DMOJ

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {

}