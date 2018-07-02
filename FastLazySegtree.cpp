#include <iostream>

using namespace std;

#define MAXN 200000

int a[MAXN * 2];
int m[MAXN * 2];

int N;

void pop(int i) {
	a[i >> 1] = (a[i] + m[i >> 1]) + (a[i ^ 1] + m[i >> 1]);
}

void popUp(int i) {
	for (; i > 1; i >>= 1) {
		pop(i);
	}
}

void buildUp() {
	for (int i = 2 * N - 1; i > 1; i -= 2) {
		pop(i);
	}
}

void modifierHelper(int i, int p) {
	a[i] += p;
	m[i] += p;
}

void modify(int L, int R, int p) {
	L += N;
	R += N;

	int LCopy = L;
	int RCopy = R;

	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
		if (L & 1) {
			modifierHelper(L, p);
		}
		if (!(R & 1)) {
			modifierHelper(R, p);
		}
	}

	popUp(LCopy);
	popUp(RCopy);
}

int realValue(int i) {
	int v = a[i];

	for (i >>= 1; i > 0; i >>= 1) {
		v += m[i];
	}

	return v;
}

int log2Query(int L, int R) {
	L += N;
	R += N;

	int sum = 0;

	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
		if (L & 1) {
			sum += realValue(L);
		}
		if (!(R & 1)) {
			sum += realValue(R);
		}
	}

	return sum;
}

int main() {
	int m, q;
	cin >> m >> N >> q;
	for (int i = 0; i < N; i++)
		cin >> a[i + N];
	buildUp();
	for (int i = 0; i < q; i++) {
		int o, l, r;
		cin >> o >> l >> r;
		l--, r--;
		if (o == 1) {
			int x;
			cin >> x;
			modify(l, r, x);
		}
		else {
			cout << log2Query(l, r) % m << endl;
		}
	}
}