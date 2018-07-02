#ifndef testrig
#define testrig
//geom
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph_uw;
typedef vector<vector<pii>> graph_w;
struct vec {
	double x, y;
};
struct line_std {
	double a, b, c;
};
struct line_pt {
	vec a, b;
};
const double dblrmx = 6666666666666666.66,
			 dblrmn = -6666666666666666.66;
double randdouble(double fMin = dblrmn, double fMax = dblrmx)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
#endif // testrig
