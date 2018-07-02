#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100005

//int bit[MAXN];
//void upd(int p, int v){
//    for(p++;p<MAXN;p+=p&-p)
//        bit[p]+=v;
//}
//
//void query(int p){
//    int res=0;
//    for(p++;p>0;p-=p&-p)
//        res+=bit[p];
//    return res;
//}

pair<pii, int> seg[MAXN];
bool pred(pair<pii, int> a, pair<pii, int> b) {
	return a.f.s - a.f.f > b.f.s - b.f.f;
}

int tk[MAXN];
vector<pair<pii, int>> sub[MAXN];

int main() {
	memset(tk, -1, sizeof tk);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &seg[i].f.f, &seg[i].f.s);
		seg[i].f.f--;
		if(seg[i].f.s < seg[i].f.f)
			seg[i].f.s += n;
		seg[i].s = i;
	}
	sort(seg, seg + n, pred);
	vector<pair<pii, int>> vld;
	for(int i = 0; i < n; i++) {
		auto kst = seg[i];
		if(tk[kst.f.f] != -1)
			sub[tk[kst.f.f]].push_back(kst);
		else {
			vld.push_back(kst);
			for(int j = kst.f.f; j < kst.f.s; j++)
				tk[j] = kst.s;
		}
	}
    sort(vld.begin(), vld.end());
    auto pp=vld.begin();
    vector<pair<pii, int>> blue,red;
    int nptr=0;

    while(nptr<vld.size()){
        while(nptr+1<vld.size() && vld[nptr+1].f.f<=pp.f.s)
            nptr++;

    }
}
