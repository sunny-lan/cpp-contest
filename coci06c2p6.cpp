#include <bits/stdc++.h>
using namespace std;

#define EPS 0.0000001

struct vec {
	double x, y;
};

typedef pair<vec, vec> line;

vec operator-(vec a, vec b) {
	return {a.x - b.x, a.y - b.y};
}

double cross(vec a, vec b) {
	return (a.x * b.y) - (a.y * b.x);
}

bool between(double a, double b, double x) {
	return x+EPS >= min(a, b) && x-EPS <= max(a, b);
}

bool ptin(line a, vec b) {
	return between(a.first.x, a.second.x, b.x) &&
		   between(a.first.y, a.second.y, b.y);
}

bool pton(line a, vec b){
    return ptin(a, b) && abs(cross(a.second - a.first, b - a.first) ) <= EPS;
}

line mrg(line a, line b) {
	vec f, s;
	if(ptin(a, b.first))
		s = b.second;
	if(ptin(a, b.second))
		s = b.first;
	if(ptin(b, a.first))
		f = a.second;
	if(ptin(b, a.second))
		f = a.first;
	return {f, s};
}

vec inter(line q, line r) {
	double a = q.first.y - q.second.y,
		   b = q.second.x - q.first.x,
		   c = -(q.first.x * a + q.first.y * b);
	double j = r.first.y - r.second.y,
		   k = r.second.x - r.first.x,
		   l = -(r.first.x * j + r.first.y * k);
	double disc = (b * j - a * k);
	if(abs(disc) <= EPS)
		return {0.0 / 0.0, 0.0 / 0.0};
	vec res = {(c * k - b * l) / disc, (a * l - c * j) / disc};
	if(!ptin(q, res) || !ptin(r, res))
		return {0.0 / 0.0, 0.0 / 0.0};
	return res;
}

#define MAXN 21

int bm[MAXN * MAXN];

int main() {
	vector<line> lns;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		lns.push_back({{x1, y1}, {x2, y2}});
	}

remstuff:
	for(int i = 0; i < lns.size(); i++)
		for(int j = i + 1; j < lns.size(); j++) {
			line a = lns[i], b = lns[j];
			if((pton(a, b.first)|| pton(a, b.second))&&abs(cross(a.second-a.first, b.second-b.first))<=EPS) {
				lns.erase(lns.begin() + j);
				lns.erase(lns.begin() + i);
				lns.push_back(mrg(a, b));
				goto remstuff;
			}
		}

	vector<vec> ints;
	for(int i = 0; i < lns.size(); i++)
		for(int j = i + 1; j < lns.size(); j++) {
			vec pt = inter(lns[i], lns[j]);
			if(pt.x != pt.x)
				continue;
			for(vec cmp:ints)
            {
                vec delt=cmp-pt;
                if(abs(delt.x)<=EPS && abs(delt.y)<=EPS)
                    goto kust;
            }
            ints.push_back(pt);
            kust:continue;
		}


	for(int i = 0; i < ints.size(); i++)
		for(int j = 0; j < lns.size(); j++)
			if(pton(lns[j], ints[i]))
				bm[i] |= 1 << j;

	int res = 0;
	for(int i = 0; i < ints.size(); i++)
		for(int j = i + 1; j < ints.size(); j++)
			for(int k = j + 1; k < ints.size(); k++)
			{
				vec a = ints[i], b = ints[j], c = ints[k];
				if(abs(cross(b - a, c - a)) <= EPS)
					continue;
				if(!(bm[i] & bm[j]))
					continue;
				if(!(bm[j] & bm[k]))
					continue;
				if(!(bm[i] & bm[k]))
					continue;
				res++;
			}

	printf("%d", res);
}
