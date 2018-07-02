
template<class T>
class ordered_set {
private:
	struct node {
		node *l, *r, *p;
		T x;
		int c, s;
	};
	node *root;
	int sztl(node *r) {
		if (r == NULL) return 0;
		else return r->s;
	}
	int update(node *r) {
		if (r != NULL) r->s = sztl(r->l) + sztl(r->r) + r->c;
		return 0;
	}
	int dlsl(node *r) {
		node *n = r->r;
		r->r = n->l;
		if (n->l != NULL) n->l->p = r;
		n->p = r->p;
		if (r->p == NULL) root = n;
		else if (r->p->l == r) r->p->l = n;
		else r->p->r = n;
		n->l = r, r->p = n;
		update(r), update(n);
		return 0;
	}
	int drsl(node *r) {
		node *n = r->l;
		r->l = n->r;
		if (n->r != NULL) n->r->p = r;
		n->p = r->p;
		if (r->p == NULL) root = n;
		else if (r->p->l == r) r->p->l = n;
		else r->p->r = n;
		n->r = r, r->p = n;
		update(r), update(n);
		return 0;
	}
	int spl(node *n) {
		if (n == NULL) return 0;
		while (n->p != NULL) {
			if (n->p->p == NULL) {
				if (n == n->p->l) drsl(n->p);
				else dlsl(n->p);
			}
			else if ((n->p->l == n) && (n->p->p->l == n->p)) drsl(n->p->p), drsl(n->p);
			else if ((n->p->r == n) && (n->p->p->r == n->p)) dlsl(n->p->p), dlsl(n->p);
			else if ((n->p->l == n) && (n->p->p->r == n->p)) drsl(n->p), dlsl(n->p);
			else dlsl(n->p), drsl(n->p);
		}
		return 0;
	}
	int clrmeme(node *r) {
		if (r == NULL) return 0;
		clrmeme(r->l), clrmeme(r->r);
		delete r;
		return 0;
	}
public:
	ordered_set() { root = NULL; }
	~ordered_set() { clrmeme(root); }

	int sztl() { return (root == NULL) ? 0 : root->s; }
	int clear() { clrmeme(root), root = NULL; return 0; }
	int search(T k) {
		node *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (r->x == k) {
				spl(r);
				return 1;
			}
			else if (r->x < k) r = r->r;
			else r = r->l;
		}
		spl(p);
		return 0;
	}
	int insert(T k) {
		node *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (r->x == k) {
				r->c++;
				update(r);
				spl(r);
				return 0;
			}
			else if (r->x < k) r = r->r;
			else r = r->l;
		}
		node *n = new node;
		n->p = p, n->l = n->r = NULL, n->x = k, n->c = n->s = 1;
		if (p == NULL) root = n;
		else if (p->x < k) p->r = n;
		else p->l = n;
		spl(n);
		return 0;
	}
	int erase(T k) {
		if (search(k)) {
			root->c--;
			update(root);
			if (root->c == 0) {
				if (root->r == NULL) {
					node *t = root->l;
					delete root;
					root = t;
				}
				else {
					node *t = root->l;
					root = root->r;
					delete root->p;
					root->p = NULL;
					node *n = root;
					while (n->l != NULL) n = n->l;
					spl(n);
					root->l = t;
					if (t != NULL) t->p = root;
					update(root);
				}
			}
			if (root != NULL) root->p = NULL;
			return 0;
		}
		else return 0;
	}
	T kth(int k) {
		node *r = root, *p = NULL;
		while (r != NULL) {
			p = r;
			if (sztl(r->l) >= k) r = r->l;
			else if (sztl(r->l) >= (k - r->c)) {
				spl(r);
				return r->x;
			}
			else k -= sztl(r->l) + r->c, r = r->r;
		}
		spl(p);
		return T();
	}
	int index(T k) {
		node *r = root, *p = NULL;
		int t = 0;
		while (r != NULL) {
			p = r;
			if (k < r->x) r = r->l;
			else if (k == r->x) {
				t += sztl(r->l);
				spl(r);
				return t;
			}
			else t += sztl(r->l) + r->c, r = r->r;
		}
		spl(p);
		return 0;
	}
	T minimum() {
		node *r = root;
		while (r->l != NULL) r = r->l;
		spl(r);
		return r->x;
	}
	T maximum() {
		node *r = root;
		while (r->r != NULL) r = r->r;
		spl(r);
		return r->x;
	}
};