#include <iostream>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <cmath>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

#define MAXN 10
#define LIM (1<<MAXN)
#define MAXV 5000000

int l, r, w;
int lw[MAXN + 1];
int rw[MAXN + 1];
int lp[LIM + 1];
int rp[LIM + 1];
int ldp[LIM + 1][LIM + 1][MAXN + 1];
int rdp[LIM + 1][LIM + 1][MAXN + 1];

//string to_binary(int value) {
//	bitset<10> bs(value);
//	return bs.to_string();
//}

int fr(int lm, int rm, int i, int t);

int fl(int lm, int rm, int i, int t) {
	/*string lmask = to_binary(lm);
	string rmask = to_binary(rm);*/
	//cout <<"left "<< lmask << " " << rmask << " " << i <<" "<< t << endl;
	int res = ldp[lm][rm][i];
	if (res != -1)
		return res;
	res = MAXV;

	if (i == l) {
		if (t > 0)
			if (lm == 0 && rm == 0)
				res = 1;
			else if (abs(lp[lm] - rp[rm]) <= w)
				res = min(res, fr(lm, rm, 0, 0) + 1);
	}
	else {
		if (lm & (1 << i))
			res = min(res, fl(lm & ~(1 << i), rm, i + 1, t + 1));
		res = min(res, fl(lm, rm, i + 1, t));
	}

	ldp[lm][rm][i] = res;
	return res;
}

int fr(int lm, int rm, int i, int t) {
	/*string lmask = to_binary(lm);
	string rmask = to_binary(rm);*/
	//cout << "right " << lmask << " " << rmask << " " << i <<" "<< t << endl;
	int res = rdp[lm][rm][i];
	if (res != -1)
		return res;
	res = MAXV;

	if (i == r) {
		if (t > 0)
			if (lm == 0 && rm == 0)
				res = 1;
			else if (abs(lp[lm] - rp[rm]) <= w)
				res = min(res, fl(lm, rm, 0, 0) + 1);
	}
	else {
		if (rm & (1 << i))
			res = min(res, fr(lm, rm & ~(1 << i), i + 1, t + 1));
		res = min(res, fr(lm, rm, i + 1, t));
	}

	rdp[lm][rm][i] = res;
	return res;
}


int main() {
	memset(ldp, -1, sizeof ldp);
	memset(rdp, -1, sizeof rdp);

	scan(l); scan(r); scan(w);

	for (int i = 0; i < l; i++)
		scan(lw[i]);

	for (int i = 0; i < r; i++)
		scan(rw[i]);

	for (int i = 0; i < LIM; i++) {
		int sum = 0;
		int tmp = i;
		for (int j = 0; j < l; j++) {
			if (tmp & 1)
				sum += lw[j];
			tmp >>= 1;
		}
		lp[i] = sum;
		sum = 0;
		tmp = i;
		for (int j = 0; j < r; j++) {
			if (tmp & 1)
				sum += rw[j];
			tmp >>= 1;
		}
		rp[i] = sum;
	}

	int lm = (1 << l) - 1;
	int rm = (1 << r) - 1;

	cout << min(fr(lm, rm, 0, 0), fl(lm, rm, 0, 0)) << endl;
	cin >> r;
}