#include <bits/stdc++.h>
using namespace std;

#define MAXN 400

void calcunity(int n, int ppl[], int ans[], int out[]) {
	for(int i = 0; i < n - 1; i++) {
		int l = 0, r = 0;
		for(int j = i; j >= 0 && ans[j] <= ans[i]; j--)
			l += ppl[j];
		for(int j = i + 1; j < n && ans[j - 1] <= ans[i]; j++)
			r += ppl[j];
		out[i] = l * r;
	}
}

int y[MAXN];
int _n;
int *_ppl;

void initgrader(int n, int ppl[], int ans[]) {
	_n = n, _ppl = ppl;
	calcunity(n, ppl, ans, y);
//	cout << "grader inited:" << endl;
//	cout << "ppl: ";
//	for(int i = 0; i < n; i++)
//		cout << ppl[i] << " ";
//	cout << endl;
//	cout << "ans: ";
//	for(int i = 0; i < n - 1; i++)
//		cout << ans[i] << " ";
//	cout << endl;
//	cout << "y: ";
//	for(int i = 0; i < n - 1; i++)
//		cout << y[i] << " ";
//	cout << endl;
}

int x[MAXN];

int query(int guess[]) {
	calcunity(_n, _ppl, guess, x);
	int res = 0;
//	cout << "query: ";
	for(int i = 0; i < _n - 1; i++) {
//		cout << guess[i] << " ";
		res += abs(x[i] - y[i]);
	}
//	cout << " = " << res << endl;
	return res;
}

int guess[MAXN];
int res[MAXN];
int u[MAXN];

void calc(int n, int v[]) {
	for(int i = 0; i < n - 1; i++)
		guess[i] = n - 1 - i;
	int mini = INT_MAX, best;
	int l=0;
	for(int i = 0; i < n - 1; i++) {
        l+=v[n-2-i];
		guess[n - 2 - i] = i;
		guess[n - 2] = i + 1;
		res[i] = query(guess);
		if(res[i] < mini)
			mini = res[i], best = i, u[n-2]=v[n-1]*l;
	}
	for(int i = 0; i < n - 1; i++)
        guess[i]=i+1;
	int ini=query(guess);
    for(int i=n-3;i>=0;i--){

    }
}

int ans[MAXN];
int ppl[MAXN];

int main() {
    int mxn=398, iter=100000;
	while(true) {
		int n = rand()%mxn+2;
		for(int i=0;i<n;i++)
            ppl[i]=rand()%100+1;
		for(int i = 1; i <= n - 1; i++)
			ans[i - 1] = i;
			for(int i=0;i<iter;i++){
		random_shuffle(ans, ans + n - 1);
		initgrader(n, ppl, ans);
		calc(n, ppl);
			}
//		cin >> n;
//		n = 7;
	}
}
