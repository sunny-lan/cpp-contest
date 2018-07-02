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

#endif // DMOJ
using namespace std;

template<class T>
class totally_not_cheating {
private:
	struct jimgao {
		jimgao *l, *r, *p;
		T x;
		int c, s;
	};
	jimgao *root;
	int size(jimgao *r) {
		if (r == NULL) return 0;
		else return r->s;
	}
	int sao_sucks(jimgao *r) {
		if (r != NULL) r->s = size(r->l) + size(r->r) + r->c;
		return 0;
	}
	int rotmgL(jimgao *r) {
		jimgao *n = r->r;
		r->r = n->l;
		if (n->l != NULL) n->l->p = r;
		n->p = r->p;
		if (r->p == NULL) root = n;
		else if (r->p->l == r) r->p->l = n;
		else r->p->r = n;
		n->l = r, r->p = n;
		sao_sucks(r), sao_sucks(n);
		return 0;
	}
	int rotmgR(jimgao *r) {
		jimgao *n = r->l;
		r->l = n->r;
		if (n->r != NULL) n->r->p = r;
		n->p = r->p;
		if (r->p == NULL) root = n;
		else if (r->p->l == r) r->p->l = n;
		else r->p->r = n;
		n->r = r, r->p = n;
		sao_sucks(r), sao_sucks(n);
		return 0;
	}
	int spray(jimgao *n) {
		if (n == NULL) return 0;
		while (n->p != NULL) {
			if (n->p->p == NULL) {
				if (n == n->p->l) rotmgR(n->p);
				else rotmgL(n->p);
			}
			else if ((n->p->l == n) && (n->p->p->l == n->p)) rotmgR(n->p->p), rotmgR(n->p);
			else if ((n->p->r == n) && (n->p->p->r == n->p)) rotmgL(n->p->p), rotmgL(n->p);
			else if ((n->p->l == n) && (n->p->p->r == n->p)) rotmgR(n->p), rotmgL(n->p);
			else rotmgL(n->p), rotmgR(n->p);
		}
		return 0;
	}
	int clearMeme(jimgao *r) {
		if (r == NULL) return 0;
		clearMeme(r->l), clearMeme(r->r);
		delete r;
		return 0;
	}
public:
	totally_not_cheating() { root = NULL; }
	~totally_not_cheating() { clearMeme(root); }

	int size() { return (root == NULL) ? 0 : root->s; }
	int clear() { clearMeme(root), root = NULL; return 0; }
	int search(T k) {
		jimgao *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (r->x == k) {
				spray(r);
				return 1;
			}
			else if (r->x < k) r = r->r;
			else r = r->l;
		}
		spray(p);
		return 0;
	}
	int insert(T k) {
		jimgao *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (r->x == k) {
				r->c++;
				sao_sucks(r);
				spray(r);
				return 0;
			}
			else if (r->x < k) r = r->r;
			else r = r->l;
		}
		jimgao *n = new jimgao;
		n->p = p, n->l = n->r = NULL, n->x = k, n->c = n->s = 1;
		if (p == NULL) root = n;
		else if (p->x < k) p->r = n;
		else p->l = n;
		spray(n);
		return 0;
	}
	int erase(T k) {
		if (search(k)) {
			root->c--;
			sao_sucks(root);
			if (root->c == 0) {
				if (root->r == NULL) {
					jimgao *t = root->l;
					delete root;
					root = t;
				}
				else {
					jimgao *t = root->l;
					root = root->r;
					delete root->p;
					root->p = NULL;
					jimgao *n = root;
					while (n->l != NULL) n = n->l;
					spray(n);
					root->l = t;
					if (t != NULL) t->p = root;
					sao_sucks(root);
				}
			}
			if (root != NULL) root->p = NULL;
			return 0;
		}
		else return 0;
	}
	T definitely_did_not_copy_and_paste(int k) {
		jimgao *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (size(r->l) >= k) r = r->l;
			else if (size(r->l) >= (k - r->c)) {
				spray(r);
				return r->x;
			}
			else k -= size(r->l) + r->c, r = r->r;
		}
		spray(p);
		return T();
	}
	int deca(T k) {
		jimgao *r = root, *p = NULL;
		int t = 0;
		while (r != NULL) {
			p = r;
			if (k < r->x) r = r->l;
			else if (k == r->x) {
				t += size(r->l);
				spray(r);
				return t;
			}
			else t += size(r->l) + r->c, r = r->r;
		}
		spray(p);
		return 0;
	}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int main() {
	int n, m; scan(n); scan(m);
	totally_not_cheating<pii> cnt;
	unordered_map<int, int> last;
	for (int i = 0; i < n; i++)
	{
		int k; scan(k);
		cnt.insert({ k,++last[k] });
	}

	int lastEnc = 0;

	for (int i = 0; i<m; i++) {
		char op; int v; scanf(" %c %d", &op, &v);
		v = v^lastEnc;
		if (op == 'I') {
			cnt.insert({ v,++last[v] });
		}
		else if (op == 'R') {
			if (last[v] != 0)
				cnt.erase({ v, last[v]-- });
		}
		else if (op == 'S') {
			lastEnc = cnt.definitely_did_not_copy_and_paste(v ).first;
			printf("%d\n", lastEnc);
		}
		else if (op == 'L') {
			if (last[v] != 0)
				lastEnc = cnt.deca({ v, 1 }) + 1;
			else
				lastEnc = -1;
			printf("%d\n", lastEnc);
		}
	}

	for (int i=1;i<=cnt.size();i++)
		printf("%d ", cnt.definitely_did_not_copy_and_paste(i).first);

	printf("\n");
}