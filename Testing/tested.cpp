#include "testrig.h"
#include <bits/stdc++.h>
using namespace std;


namespace tested {
    //geom
    double cross(vec a, vec b);
    line_std to_std(line_pt ln);
    vec intersection(line_std a, line_std b);
    vector<vec> convex(vector<vec> pts);

    //combinatorics
    ll binomial_coeff(int n, int k);

    //graph
    vector<int> cut_nodes(vector<vector<int>> adj);
    vector<vector<int>> scc(vector<vector<int>> adj);
}
