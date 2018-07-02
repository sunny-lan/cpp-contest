#define _CRT_SECURE_NO_WARNINGS

#ifdef DMOJ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required
using namespace std;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#endif // DMOJ

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ordered_set <int> s;
#define MAXN 100000

int p[MAXN];


int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

int main() {
	int n, m; scan(n); scan(m);
	
	for (int i = 0; i < n; i++) {

	}
}