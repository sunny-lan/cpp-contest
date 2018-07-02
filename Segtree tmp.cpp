#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

//template parameters
#define NUM int
//#define IDENTITY 0
//#define CMB(a, b) a+b
const int n = 250000;

//template begins
NUM t[n * 2 + 100];
NUM d[n + 100];

inline int popcnt(int x)
{
	x -= ((x >> 1) & 0x55555555);
	x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
	x = (((x >> 4) + x) & 0x0f0f0f0f);
	x += (x >> 8);
	x += (x >> 16);
	return x & 0x0000003f;
}

inline int clz(int x)
{
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return 32 - popcnt(x);
}

int h = sizeof(int) * 8 - clz(n);

//refreshes value at seg p, k is size of segment
void calc(int p, int k) {
	//if there was no modification, update from children
	if (d[p] == 0) t[p] = t[p << 1] + t[p << 1 | 1];
	//otherwise assign pending lazy value
	else t[p] = d[p] * k; //multiply by k (since all values are set to k)
}

void apply(int p, int value, int k) {
	//assign actual value
	t[p] = value * k;
	// if this is not a leaf node
	if (p < n) d[p] = value; //set as lazy - why?
}

//propagates changes from leaf nodes l to r up tree
void build(int l, int r) {
	int k = 2;//stores size of segment
	for (
		l += n, r += n - 1; //set up bounds
		l > 1;
		k <<= 1 //size of segment doubles every level 
		)
	{
		l >>= 1, r >>= 1; //move down
		//update every node between l and r pointers
		for (int i = r; i >= l; --i) calc(i, k);
	}
}

//propagates lazy changes down to leaf nodes l to r
void push(int l, int r) {
	int s = h, //stores the current level of tree we are on
		k = 1 << (h - 1); //stores the current size of the segment
	for (l += n, r += n - 1;//set up ranges
		s > 0;
		--s, k >>= 1//inc level and seg size
		)
		for (
			//use magical bit tricks to find indices
			int i = l >> s; i <= r >> s;
			++i)
			//if there is a pending update
			if (d[i] != 0) {
				apply(i << 1, d[i], k);
				apply(i << 1 | 1, d[i], k);
				d[i] = 0;
			}
}

//NOTE: by performing build and push, it guarentees the tree is
//      valid for all elements from l to r

void update(int l, int r, int value) {
	if (value == 0) return;
	//make sure no lazy updates are pending before performing this update, since order matters
	push(l, l + 1);
	push(r - 1, r);

	//do standard update
	int l0 = l, r0 = r, k = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (l & 1) apply(l++, value, k);
		if (r & 1) apply(--r, value, k);
	}

	//propagate changes up tree
	build(l0, l0 + 1);
	build(r0 - 1, r0);
}

int query(int l, int r) 
{
	//first apply any pending changes
	push(l, l + 1);
	push(r - 1, r);
	
	//then do standard query
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}
//template end

int main() {
	int nx;
	cin >> nx;
	for (int i = 1; i <= nx; i++)
		cin >> t[i + n];
	build(1, nx);

	int qx; cin >> qx;
	for (int i = 0; i < qx; i++) {
		int op, l, r; cin >> op >> l >> r;
		if (op == 1)
			cout << query(l, r) << endl;
		else {
			int x; cin >> x;
			update(l, r, x);
		}
		cout << "Val:  ";
		for (int i = 1; i <= nx; i++)
			cout << query(i, i + 1) << " ";
		cout << endl;
	}
	cin >> nx;
}