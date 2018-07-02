#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAXN 1000002ull
#define BM (1ull<<43)

ull lst[MAXN];

ull curr;
ull prv = 0ull;
bool fwd = false;

inline ull tr(char dir) {
	if (fwd!=(dir=='>'))
	{
		return prv;
	}
	else {
		ull enc = lst[curr] >> 44;
		return enc^prv;
	}
}

int main() {
	ull free = MAXN + 1ull;
	for (ull i = 0ull; i < MAXN; i++) {
		lst[i] = free;
		free = i;
	}
	ull start = free;
	free = lst[free];
	ull stop = free;
	free = lst[free];
	lst[start] = stop << 44;
	lst[stop] = start << 44;
	curr = stop;

	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char op; scanf(" %c", &op);
		if (op == '<' || op == '>') {
			int tmp = curr;
			curr = tr(op);
			fwd = (op == '>');
			prv = tmp;
		}
		else if (op == '=') {
			ll v; scanf("%lld", &v);
			ull av = 0;
			if (v < 0) {
				av |= BM;
				v = -v;
			}
			av |= ((ull)v);

			lst[curr] >>= 44, lst[curr] <<= 44;
			lst[curr] |= av;
		}
		else if (op == '+') {
			ll v; scanf("%lld", &v);
			ull av = 0;
			if (v < 0) {
				av |= BM;
				v = -v;
			}
			av |= ((ull)v);

			ull nw = free;
			free = lst[free];
			lst[nw] = av;

			ull pv = tr('<');
			lst[nw] |= ((pv^curr) << 44);
			lst[curr] ^= (pv^nw) << 44;
			lst[pv] ^= (curr^nw) << 44;

			prv = curr, fwd = false;
			curr = nw;
		}
		else if (op == '-') {
			ull nx = tr('>'),
				pv = tr('<');
			lst[pv] ^= (curr^nx) << 44;
			lst[nx] ^= (curr^pv) << 44;

			lst[curr] = free;
			free = curr;

			prv = pv, fwd = true;
			curr = nx;
		}
		else if (op == '!') {
			ll ans = (ll)(lst[curr] & ((1ull << 43) - 1ull));
			if (lst[curr] & BM)
				printf("-");
			printf("%lld\n", ans);
		}
	}
	//scan(m);
}