#include<iostream>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//template parameters
#define NUM long long
#define IDENTITY 0
#define CMB_UPDATE(a, b) a+b
#define MULT_UPDATE(a,b) a*b
#define CMB_QUERY(a, b) a+b

const int n = 200002;

//template begins
NUM t[n * 2];
NUM d[n]; //represents value needed to be propagated to children

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
	t[p] = CMB_QUERY(t[p << 1], t[p << 1 | 1]);
	//otherwise assign pending lazy value
	t[p] = CMB_UPDATE(t[p], MULT_UPDATE(d[p], k)); //multiply by k (since all values are set to k)
}

void apply(int p, NUM value, int k) {
	t[p] = CMB_UPDATE(t[p], MULT_UPDATE(value, k));
	// if this is not a leaf node
	if (p < n) d[p] = CMB_UPDATE(d[p], value);
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
		l >>= 1, r >>= 1; //move up
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
		--s, k >>= 1//inc level and half seg size
		)
		for (
			//find indices of l and r
			int i = l >> s; i <= r >> s;
			++i)
			//if there is a pending update
			if (d[i] != IDENTITY) {
				apply(i << 1, d[i], k >> 1);
				apply(i << 1 | 1, d[i], k >> 1);
				d[i] = IDENTITY;
			}
}

//NOTE: by performing build and push, it guarentees the tree is
//      valid for all elements from l to r

void update(int l, int r, NUM value) {
	if (value == IDENTITY) return;
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
	NUM res = IDENTITY;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = CMB_QUERY(res, t[l++]);
		if (r & 1) res = CMB_QUERY(res, t[--r]);
	}
	return res;
}
//template end

int main() {
	int nx;
	NUM m; int q; scan(m); scan(nx); scan(q);
	for (int i = 1; i <= nx; i++)
		scan(t[i + n]);

	build(1, nx);

	for (int i = 0; i < q; i++) {
		int op, l, r; scan(op); scan(l); scan(r);
		if (op == 1)
		{
			NUM x; scan(x);
			update(l, r + 1, x);
		}
		else {
			NUM out = query(l, r + 1);
			//cout << out << endl;
			printf("%lld\n", out  % m);
		}
	}
	cin >> nx;
}