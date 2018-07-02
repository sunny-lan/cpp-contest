#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

pii operator -(pii a, pii b) {
	return {a.x - b.x, a.y - b.y};
}

inline int cros(pii a, pii b) {
	return a.x * b.y - a.y * b.x;
}

inline double dst(pii a, pii b) {
	pii d = a - b;
	return sqrt(d.x * d.x + d.y * d.y);
}

#define MAXN 4001

pii pt[MAXN];
bool pred(pii a, pii b) {
	return cros(a - pt[0], b - pt[0]) <= 0;
}

vector<pii> hul;

int main() {
	int n;
	scanf("%d", &n);
	double maxi = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &pt[i].x, &pt[i].y);
		if(i > 0)
			if(pt[i].x < pt[0].x || (pt[i].x == pt[0].x && pt[i].y < pt[0].y))
				swap(pt[0], pt[i]);
	}
	sort(pt + 1, pt + n, pred);
	hul.push_back(pt[0]), hul.push_back(pt[1]);
	for(int i = 2; i < n; i++) {
		while(hul.size() > 1 && cros(pt[i] - hul.back(), hul.back() - hul[hul.size() - 2]) <= 0)
			hul.pop_back();
		hul.push_back(pt[i]);
	}
//    printf("re\n");
//    for(pii i:hul)
//        printf("%d %d\n", i);
	double mx = 0;
	for(int i = 0; i < hul.size(); i++)
		for(int j = 0; j < i; j++)
			for(int k = 0; k < j; k++) {
				double a = dst(hul[i], hul[j]),
					   b = dst(hul[j], hul[k]),
					   c = dst(hul[k], hul[i]),
					   s = (a + b + c) / 2;
				mx = max(mx, sqrt(s * (s - a) * (s - b) * (s - c)));
			}

	printf("%lf\n", mx);
}
