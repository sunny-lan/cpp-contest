#include "testrig.h"
#include <bits/stdc++.h>
using namespace std;

namespace correct {
//geom
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}
line_std to_std(line_pt ln);
vec intersection(line_std a, line_std b);
vector<vec> convex(vector<vec> pts);

//combinatorics
ll binomial_coeff(int n, int k) {
	k = min(k, n - k);
	ll num = 1, den = 1;
	for(int i = 1; i <= k; i++)
		num *= n + 1 - i, den *= i;
	return num / den;
}

//graph
vector<int> dijkstras(graph_w adj);
vector<int> cut_nodes(graph_uw adj);
vector<pii> cut_edges(graph_uw adj);
vector<vector<int>> scc(graph_uw adj);
}
