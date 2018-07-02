#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

#define MAXN 100001

int n;
int x[MAXN], y[MAXN];
bool v[MAXN];

bool between(int x, int a, int b) {
	return x >= min(a, b) && x <= max(a, b);
}

bool inside(pii a, pii b, pii c) {
	return between(c.x, a.x, b.x) && between(c.y, a.y, b.y);
}

void kustify(pii a, pii b) {
	for(int i = 0; i < n; i++)
		if(inside(a, b, {x[i], y[i]}))
			v[i] = true;
}
int llll;
bool chk(pii a, pii b, pii c, pii d, pii e, pii f) {
	memset(v, false, sizeof v);
//	if(a!=c){
        kustify(a, b);
        kustify(c, d);
//	}
	kustify(e, f);
    int mxx = -INT_MAX, mxy = -INT_MAX, mnx = INT_MAX, mny = INT_MAX;
    bool flg=false;
	for(int i = 0; i < n; i++)
		if(!v[i])
			{
			    if(a==c){
                    mxx = max(mxx, x[i]);
                    mnx = min(mnx, x[i]);
                    mxy = max(mxy, y[i]);
                    mny = min(mny, y[i]);
                    flg=true;
			    }else{
                    return false;
			    }
			}
    if(flg && a==c)
        if(max(mxx-mnx, mxy-mny)>llll)return false;
	return true;
}


int maxx = -INT_MAX, maxy = INT_MAX, minx = -INT_MAX, miny = INT_MAX;
vector<pii> top, bot, lll, rrr;
bool chk2(int l){
    llll=l;
    int a1=top.front().second, a2=lll.front().second;
    pii c={maxx, maxy};
    if(chk(
        {x[a1], y[a1]}, {x[a1]+l, y[a1]+l},
        {x[a2], y[a2]}, {x[a2]+l, y[a2]+l},
        c, {c.x-l, c.y-l}
           ))
           return true;
    a1=top.back().second, a2=rrr.front().second;
    c={minx, maxy};
     if(chk(
        {x[a1], y[a1]}, {x[a1]-l, y[a1]+l},
        {x[a2], y[a2]}, {x[a2]-l, y[a2]+l},
        c, {c.x+l, c.y-l}
           ))
           return true;
     a1=bot.back().second, a2=rrr.back().second;
    c={minx, miny};
     if(chk(
        {x[a1], y[a1]}, {x[a1]-l, y[a1]-l},
        {x[a2], y[a2]}, {x[a2]-l, y[a2]-l},
        c, {c.x+l, c.y+l}
           ))
           return true;
           a1=bot.front().second, a2=lll.back().second;
    c={minx, miny};
     if(chk(
        {x[a1], y[a1]}, {x[a1]+l, y[a1]-l},
        {x[a2], y[a2]}, {x[a2]+l, y[a2]-l},
        c, {c.x-l, c.y+l}
           ))
           return true;
    return false;
}

int main() {
	freopen("C:\\Users\\sunny\\Desktop\\DATA41.txt", "r", stdin);
	for(int test = 0; test < 10; test++) {
        top.clear(), bot.clear(), lll.clear(), rrr.clear();
		scanf("%d", &n);
		vector<int> xc, yc;
		 maxx = -INT_MAX, maxy = -INT_MAX, minx = INT_MAX, miny = INT_MAX;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
			maxx = max(maxx, x[i]);
			minx = min(minx, x[i]);
			maxy = max(maxy, y[i]);
			miny = min(miny, y[i]);
			xc.push_back(x[i]);
			yc.push_back(y[i]);
		}
		for(int i = 0; i < n; i++) {
			if(x[i] == minx)
				lll.push_back({y[i], i});
			if(x[i] == maxx)
				rrr.push_back({y[i], i});
			if(y[i] == miny)
				top.push_back({x[i], i});
			if(y[i] == maxy)
				bot.push_back({x[i], i});
		}
		sort(top.begin(), top.end());
		sort(bot.begin(), bot.end());
		sort(lll.begin(), lll.end());
		sort(rrr.begin(), rrr.end());

        int l=0,h=1<<30;
        while(l<h){
            int m=(l+h)/2;
            if(!chk2(m))
                l=m+1;
            else
                h=m;
        }
        printf("%d\n", l);
	}
}

