#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

#ifdef _MSC_VER
#define pc(x) putchar(x)
#define gc() getchar()
#else
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
#endif // _MSVC_VER

inline void writeInt(int n)
{
	register int N = n, rev, count = 0;
	rev = N;
	while ((rev % 10) == 0) { count++; rev /= 10; } //obtain the count of the number of 0s
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }  //store reverse of N in rev
	while (rev != 0) { pc(rev % 10 + '0'); rev /= 10; }
	while (count--) pc('0');
}

#define scan(x) do{while((x=gc())<'0'); for(x-='0'; '0'<=(_=gc()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MOD 262144
#define MODM 262143

#define MAXN 262144
#define MAXA 262144
#define bs 512
#define hbs (bs/2)
#define MAXB ((MAXN/bs)+1)

int a[MAXN];

int psa[MAXB][MAXA];
int ans[MAXB][MAXB];

int cnt[MAXA];
int dirty[MAXA];

int main() {
//freopen("C:\\Users\\Sunny\\Desktop\\data.txt", "r", stdin);
	memset(psa, 0, sizeof psa);
	memset(ans, 0, sizeof ans);
	memset(dirty, -1, sizeof dirty);
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++)scan(a[i]);
	int blks = n / bs;

	for (int sblk = 0; sblk < blks; sblk++) {
		int st = sblk*bs, ed = st + bs;
		for (int i = 0; i < MAXA; i++)
			psa[sblk + 1][i] += psa[sblk][i];
		for (int i = st; i < ed; i++) {
			psa[sblk + 1][a[i]]++;
			for (int j = 0; j <= sblk; j++) {
				if (i == st)ans[j][sblk + 1] = ans[j][sblk];
				ans[j][sblk + 1] += ((psa[sblk + 1][a[i]] - psa[j][a[i]]) << 1) - 1;
				ans[j][sblk + 1] &= MODM;
			}
		}
	}

	int last = 0;
	for (int i = 0; i < q; i++) {
		int x, y; scan(x); scan(y);
		x ^= last, y ^= last;
		int l = x, r = y + 1;
		int sb = (l + bs - 1) / bs,
			eb = r / bs;
		int res;
		if (sb >= eb) {
			if (eb<blks && r - l > hbs) {
				res = ans[eb][eb+1 ];
				int bst = eb*bs;
				for (int j =bst; j < l; j++) {
					if (dirty[a[j]] != i) {
						cnt[a[j]] = ((psa[eb+1][a[j]] - psa[eb][a[j]]) << 1) - 1;
						dirty[a[j]] = i;
					}
					res -= cnt[a[j]]&MODM;
					res += MOD;
					res &= MODM;
					cnt[a[j]] -= 2;
				}
				bst += bs;
				for (int j = r; j <bst; j++) {
					if (dirty[a[j]] != i) {
						cnt[a[j]] = ((psa[eb + 1][a[j]] - psa[eb][a[j]]) << 1) - 1;
						dirty[a[j]] = i;
					}
					res -= cnt[a[j]] & MODM;
					res += MOD;
					res &= MODM;
					cnt[a[j]] -= 2;
				}
			}
			else {
				res = 0;
				for (int j = l; j < r; j++) {
					if (dirty[a[j]] != i) {
						cnt[a[j]] = 1;
						dirty[a[j]] = i;
					}
					res += cnt[a[j]];
					cnt[a[j]] += 2;
				}
			}
		}
		else {
			res = ans[sb][eb];
			int bst = sb*bs;
			/*if (l < bst - hbs) {

			}
			else {*/
				for (int j = l; j < bst; j++) {
					if (dirty[a[j]] != i) {
						cnt[a[j]] = ((psa[eb][a[j]] - psa[sb][a[j]]) << 1) | 1;
						dirty[a[j]] = i;
					}
					res += cnt[a[j]];
					cnt[a[j]] += 2;
				}
			//}
			for (int j = eb*bs; j < r; j++) {
				if (dirty[a[j]] != i) {
					cnt[a[j]] = ((psa[eb][a[j]] - psa[sb][a[j]]) << 1) | 1;
					dirty[a[j]] = i;
				}
				res += cnt[a[j]];
				cnt[a[j]] += 2;
			}
		}
		res &= MODM;
		/*writeInt(res);
		pc('\n');*/
		last = res;
	}
}