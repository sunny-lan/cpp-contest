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

int main() {

}

//lower_bound
//finds the first element that is >= than val
//lo=0, hi=n
//while lo<hi:
//  mid=(lo+hi)/2
//  if f(mid)>=val:
//     hi=mid
//  else:
//     lo=mid+1

//upper_bound
//finds the first element that is > than val
//lo=0, hi=n
//while lo<hi:
//  mid=(lo+hi)/2
//  if f(mid)>x:
//     hi=mid
//  else:
//     lo=mid+1

//template parameters
#define MAXN 100000
#define NUM int

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y < MAXN; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

//not sure if works
void construct(NUM *val) {
	for (int i = 0; i <= n; i++) {
		bit[i] += val[i];
		bit[i + (i&-i)] += bit[i];
	}
}

//3d rectangular prism query
//NUM q2(int x1, int y1, int z1, int x2, int y2, int z2) {
//	return query(x2, y2, z2)
//		- query(x1, y2, z2) - query(x2, y1, z2) - query(x2, y2, z1)
//		+ query(x2, y1, z1) + query(x1, y2, z1) + query(x1, y1, z2)
//		- query(x1, y1, z1);
//}
//template end

struct line {
	double b, m;
	double l, r;
};

bool pred1(line a, line b) {
	return a.m > b.m;
}

bool pred2(line a, double b) {
	return a.r < b;
}

double intersection(line a, line b) {
	return (b.b - a.b) / (a.m - b.m);
}

vector<line> preproc(vector<line> lines) {
	sort(lines.begin(), lines.end(), pred1);
	vector<line> res;
	lines[0].l = -INFINITY;
	res.push_back(lines[0]);
	for (int i = 1; i < lines.size(); i++) {
		line& c = lines[i];
		while (true) {
			auto l = res.rbegin();
			double x = intersection(*l, c);
			if (l->l < x) {
				l->r = c.l = x;
				break;
			}
			res.pop_back();
		}
		res.push_back(c);
	}
	res[res.size() - 1].r = INFINITY;
	return res;
}

int findRange(double x, vector<line> lines) {
	int hi = lines.size(),
		lo = 0;
	while (lo < hi) {
		int mid = (hi + lo) / 2;
		if (lines[mid].r < x)
			lo = mid + 1;
		else if (lines[mid].l > x)
			hi = mid;
		else return mid;
	}
	return -1;
}

double f(double x, vector<line> lines) {
	line l = lines[findRange(x, lines)];
	return l.b + x*l.m;
}

int popcnt(ull w) {
	w -= (w >> 1) & 0x5555555555555555ULL;
	w = (w & 0x3333333333333333ULL) + ((w >> 2) & 0x3333333333333333ULL);
	w = (w + (w >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
	return int((w * 0x0101010101010101ULL) >> 56);
}

int popcnt(int i)
{
	// Java: use >>> instead of >>
	// C or C++: use uint32_t
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

#define MAXN 100000

vector<int> adj[MAXN];

bool cut[MAXN];
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int time = 0;
void dfs(int i, int j = -1) {
	if (visited[i])return;
	visited[i] = true;
	disc[i] = low[i] = ++time;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			dfs(neigh, i);
			low[i] = min(low[i], low[neigh]);
			if (j != -1 && low[neigh] >= disc[i])
				cut[i] = true;
		}
	}
	if (j == -1 && cnt > 1)
		cut[i] = true;
}

#define MAXN 100000

bool inq[MAXN];

ll *du;
vector<pii> *adj;

void dij(int src) {
	memset(inq, false, sizeof inq);
	du[src] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({ 0,src });
	while (!q.empty()) {
		int curr = q.top().second; q.pop();
		inq[curr] = false;
		for (pii neigh : adj[curr])
		{
			ll alt = neigh.second + du[curr];
			if (alt < du[neigh.first]) {
				du[neigh.first] = alt;
				if (!inq[neigh.first]) {
					q.push({ alt, neigh.first });
					inq[neigh.first] = true;
				}
			}
		}
	}
}

const int MAXN = 100000;
int n;

//template begin
int disjoint[MAXN];

void construct() {
	for (int i = 0; i < n; i++)
		disjoint[i] = i;
}

int find(int x) {
	if (disjoint[x] == x)
		return x;
	return disjoint[x] = find(disjoint[x]);
}

bool cmp(int x, int y) {
	return find(x) == find(y);
}

bool merge(int x, int y) {
	disjoint[find(y)] = find(x);
}
//template end

struct vec2 {
	double x, y;

	vec2(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

vec2 operator -(vec2 a, vec2 b) {
	return vec2(a.x - b.x, a.y - b.y);
}

double cross(vec2 a, vec2 b) {
	return a.x*b.y - b.x*a.y;
}

double dot(vec2 a, vec2 b) {
	return a.x*b.x + a.y*b.y;
}

//finds if two rectangles intersect
bool rectInter(vec2 a0, vec2 a1, vec2 b0, vec2 b1) {
	if (a0.x > a1.x)swap(a0.x, a1.x);
	if (a0.y > a1.y)swap(a0.y, a1.y);
	if (b0.x > b1.x)swap(b0.x, b1.x);
	if (b0.y > b1.y)swap(b0.y, b1.y);
	return a0.x < b1.x
		&& a1.x > b0.x
		&& a0.y < b1.y
		&& a1.y > b0.y;
}

//intersection between two line segments
//includes endpoints of line segments
bool segmentInter(vec2 a0, vec2 a1, vec2 b0, vec2 b1) {
	double crs0 = cross(a1 - a0, b0 - a0),
		crs1 = cross(a1 - a0, b1 - a0);
	if (crs0 == 0 || crs1 == 0)return true; //remove this line to make it exclusive
	if (!rectInter(a0, a1, b0, b1))return false;
	return crs0*crs1 < 0;
}

#define NUM ll

//finds a*k mod m
NUM mult_mod(NUM a, NUM k, NUM m) {
	NUM res = 0;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res += cur,
			res %= m;
		cur += cur;
		cur %= m;
		k >>= 1;
	}
	return res;
}

//finds a^k mod m
NUM pow_mod(NUM a, NUM k, NUM m) {
	NUM res = 1;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res *= cur,
			res %= m;
		cur *= cur;
		cur %= m;
		k >>= 1;
	}
	return res;
}

//finds a^k mod m (supports larger pows)
NUM pow_mod(NUM a, NUM k, NUM m) {
	NUM res = 1;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res = mult_mod(cur, res, m);
		cur = mult_mod(cur, cur, m);
		k >>= 1;
	}
	return res;
}


//finds mod inverse of a for a prime
//aka finds x such that x*a = 1 (mod p)
NUM inverse_mod(NUM a, NUM p) {
	return pow_mod(a, p - 2, p);
}

#define MAXN 2000
NUM c[MAXN];

//calculates row of pascals triangle
// aka n Cr k, n Cr k-1, n Cr k-2, ... n Cr 0
// c[i] = n cR i for i from 0 to k
NUM pascal_row(NUM n, int k) {
	c[0] = 1;
	for (int i = 0; i < k; ++i)
	{
		c[i + 1] = c[i];
		c[i + 1] *= (n - i);
		c[i + 1] /= (i + 1);
	}
	return c[k];
}
//calculates row of pascals triangle mod a prime
NUM pascal_row_mod(NUM n, int k, NUM p) {
	c[0] = 1;
	for (int i = 0; i < k; ++i)
	{
		c[i + 1] = c[i];
		c[i + 1] *= (n - i);
		c[i + 1] %= p;
		c[i + 1] *= inverse_mod(i + 1, p);
		c[i + 1] %= p;
	}
	return c[k];
}

//calculates diagonal of pascals triangle
// aka n+k Cr k, n+k-1 Cr k-1, n+k-2 Cr k-2, ... n Cr 0
// c[i] = n+i cR i for i from 0 to k
NUM pascal_diag(NUM n, int k) {
	c[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		c[i] = c[i - 1];
		c[i] *= (n + i);
		c[i] /= i;
	}
	return c[k];
}

//calculates diagonal of pascals triangle mod a prime
NUM pascal_diag_mod(NUM n, int k, NUM p) {
	c[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		c[i] = c[i - 1];
		c[i] *= (n + i);
		c[i] %= p;
		c[i] *= inverse_mod(i, p);
		c[i] %= p;
	}
	return c[k];
}

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(NUM d, NUM n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	NUM a = 2 + rand() % (n - 4);

	// Compute a^d % n
	NUM x = pow_mod(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i)   d does not reach n-1
	// (ii)  (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}

	// Return composite
	return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(NUM n, NUM k)
{
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	NUM d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given nber of 'k' times
	for (NUM i = 0; i < k; i++)
		if (miillerTest(d, n) == false)
			return false;

	return true;
}

//finds gcd of two numbers
NUM gcd(NUM a, NUM b) {
	return b == 0 ? a : gcd(b, a % b);
}

#define MAXN 500

int n;
int adj[MAXN][MAXN];

int p[MAXN];

int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src , INT_MAX });
	while (!q.empty()) {
		pii i = q.front(); q.pop();
		if (i.first == dst)return i.second;
		for (int j = 0; j < n; j++)if (adj[i.first][j] > 0)
			if (p[j] == -1)
				p[j] = i.first,
				q.push({ j, min(i.second, adj[i.first][j]) });
	}
	return -1;
}

int karp(int src, int dst) {
	int res = 0;
	while (true) {
		int af = bfs(src, dst);
		if (af <= 0)break;
		res += af;
		int cur = dst;
		while (cur != src) {
			int par = p[cur];
			adj[par][cur] -= af;
			adj[cur][par] += af;
			cur = par;
		}
	}
	return res;
}

#define MAXN 10001

int vals[MAXN];

int dp[2][MAXN + 1];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = max(vals[i - 1], dp[0][i - 1] + vals[i - 1]);
		dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}

	cout << "Out:" << max(dp[0][n], dp[1][n]) << endl;

	cin >> n;

	return 0;
}

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

//GUD CONTENT:
//sum for rectangle prism in any dimension
//let (a1,a2,...,an) be the first point
//let (b1,b2,...,bn) be the second point (should have larger coordinates)
//answer should be sum of psa(...) for all combinations of a and b for each dimension
//each term of sum can either have positive sign or negative sign.
//let bcnt = number of dimensions in b
//then if (bcnt % 2 == (num_dimensions + 1) % 2) then it should have negative sign
//otherwise positive sign

vector<int> dimension;

int getIdx(const vector<int>& point) {
	int base = 1;
	int idx = 0;
	for (int i = 0; i < dimension.size(); i++) {
		idx += point[i] * base;
		base *= dimension[i];
	}
	return idx;
}

void construct(vector<int> &psa) {
	int d = 1;
	for (int i = 0; i < dimension.size(); i++) {
		int dim = dimension[i] * d;
		for (int j = d; j < psa.size(); j++)
			if ((j - d) / dim == j / dim)
				psa[j] += psa[j - d];
		d = dim;
	}
}

#define MAXN 200001

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	ll val;
	ll lazy;
	bool isLazy;
};

ll dat[MAXN];
seg tree[MAXN * 3];

void push_up(int i) {
	tree[i].val =
		tree[i << 1].val +
		tree[i << 1 | 1].val;
}

void apply(int i, ll lazy) {
	tree[i].val += lazy * (tree[i].r - tree[i].l);
	tree[i].lazy += lazy;
	tree[i].isLazy = true;
}

void push_down(int i) {
	if (!tree[i].isLazy) return;
	apply(i << 1, tree[i].lazy);
	apply(i << 1 | 1, tree[i].lazy);

	tree[i].isLazy = false;
	tree[i].lazy = 0;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	if (l + 1 == r) {
		tree[i].val = dat[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int l, int r, ll x, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, i << 1); update(l, r, x, i << 1 | 1);
	push_up(i);
}

ll query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

//template begin
//NOTE: indices are indexed at 0, in the form [l, r)
#define MAXN 100000
int n;  // array size

template <typename T>
void build(T *t, T(*combiner)(T, T)) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

template <typename T>
void modify(int p, T value, T *t, T(*combiner)(T, T)) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename T>
T query(int l, int r, T *t, T(*combiner)(T, T)) {  // sum on interval [l, r)
	T res;
	bool flag = false; //prevents needing identity
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) (res = flag ? combiner(res, t[l++]) : t[l++]), flag = true;
		if (r & 1) (res = flag ? combiner(res, t[--r]) : t[--r]), flag = true;
	}
	return res;
}
//template end

#define MAXN 100000
#define MAXB 17

#define NUM int

bool pred(NUM a, NUM b) {
	return a < b;
}

NUM sparse[MAXB][MAXN * 2];

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

//range is exclusive [i,j)
inline NUM query(int i, int j) {
	int bsI = count_bits(j - i);
	NUM a = sparse[bsI][i],
		b = sparse[bsI][j - (1 << bsI)];
	return pred(a, b) ? a : b;
}

inline void construct(int n) {
	int bs = 1, bsI = 0;
	bs <<= 1, bsI++;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++) {
			NUM a = sparse[bsI - 1][i], b = sparse[bsI - 1][i + (bs >> 1)];
			sparse[bsI][i] = pred(a, b) ? a : b;
		}
		bs <<= 1, bsI++;
	}
}

NUM* val = sparse[0];

#define MAXN 50001
#define MAXM 100001
#define MAXL 20


int n, m;
vector<pii> adj[MAXN];

int sparse2[MAXL][MAXN * 2];

int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

//finds lca
int query2(int i, int j) {
	if (i > j)return query2(j, i);
	int bsI = count_bits(j - i);
	return min(sparse2[bsI][i], sparse2[bsI][j - (1 << bsI)]);
}

void construct2(const vector<int> &val) {
	int bs = 1, bsI = 0, n = val.size();
	for (int i = 0; i < n; i++)sparse2[bsI][i] = val[i];
	bs <<= 1, bsI++;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++)
			sparse2[bsI][i] = min(sparse2[bsI - 1][i], sparse2[bsI - 1][i + (bs >> 1)]);
		bs <<= 1, bsI++;
	}
}


int sparsePar[MAXL][MAXN];
int sparse[MAXL][MAXN];
int h[MAXN];
vector<int> tour;
int first[MAXN];

void dfs(int i, int j) {
	sparsePar[0][i] = j;
	first[i] = tour.size(); tour.push_back(h[i]);
	for (pii neigh : adj[i]) {
		int k = neigh.first;
		if (k == j)continue;
		sparse[0][k] = neigh.second;
		h[k] = h[i] + 1;
		dfs(k, i);
		tour.push_back(h[i]);
	}
}

void construct() {
	int bs = 2, lvl = 1;
	while (bs < n) {
		for (int i = 0; i < n; i++) {
			int par1 = sparsePar[lvl - 1][i],
				par2 = sparsePar[lvl][i] = sparsePar[lvl - 1][par1];
			sparse[lvl][i] = max(sparse[lvl - 1][i], sparse[lvl - 1][par1]);
		}
		bs <<= 1, lvl++;
	}

	construct2(tour);
}

//finds max on path in tree
int query(int a, int b) {
	int maxi = 0;
	while (a != b) {
		int lca = query2(first[a], first[b] + 1);
		if (h[a] > h[b]) {
			int msb = count_bits(h[a] - lca);
			maxi = max(maxi, sparse[msb][a]);
			a = sparsePar[msb][a];
		}
		else {
			int msb = count_bits(h[b] - lca);
			maxi = max(maxi, sparse[msb][b]);
			b = sparsePar[msb][b];
		}
	}
	return maxi;
}

void find_and_replace(string& source, string const& find, string const& replace)
{
	for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}

#define MAXN 500000

vector<int> adj[MAXN];
int gidx = 0;
int disc[MAXN];
int low[MAXN];
stack<int> S;
bool ins[MAXN];
vector<vector<int>> comps;
void dfs(int v) {
	disc[v] = gidx;
	low[v] = gidx;
	gidx++;
	S.push(v);
	ins[v] = true;
	for (int w : adj[v]) {
		if (disc[w] == -1) {
			dfs(w);
			low[v] = min(low[v], low[w]);
		}
		else if (ins[w]) {
			low[v] = min(low[v], disc[w]);
		}
	}
	if (disc[v] == low[v]) {
		vector<int> scc;
		int w;
		do {
			w = S.top(); S.pop();
			ins[w] = false;
			scc.push_back(w);
		} while (w != v);
		comps.push_back(scc);
	}
}

void tarjan(int n) {
	memset(disc, -1, sizeof disc);
	for (int i = 0; i < n; i++)
		if (disc[i] == -1)
			dfs(i);
}

#define MAXN 30000
#define MAXL 30

int ptr[26][MAXN*MAXL];
int eow[MAXN*MAXL];
int nw;

void init() {
	memset(ptr, -1, sizeof ptr);
	nw = 1;
}

void ins(const string& s, int i = 0, int j = 0) {
	if (i == s.length()) {
		eow[j]++;
		return;
	}
	int kust = s[i] - 'a';
	if (ptr[kust][j] == -1)
		ptr[kust][j] = nw++;
	//do update here
	ins(s, i + 1, ptr[s[i]][j]);
}

void traverse(const string& s, int i = 0, int j = 0) {
	if (i == s.length())return;
	int kust = s[i] - 'a';
	if (ptr[kust][j] == -1)return;
	//do proc here
	traverse(s, i + 1, ptr[kust][j]);
}