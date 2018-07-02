#include <unordered_map>
#include <stdio.h>
#include <list>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
unordered_map<long long, unordered_map<long long, long long>> m;
unordered_map<long long, long long> a;
unordered_map<long long, long long> b;
int main()
{
    int n, q, i;
    scan(n); scan(q);
    m.reserve(200000);
    a.rehash(9999991);
    b.rehash(9999991);
    for (i = 0; i < n; i++) {
        long long x, y, v;
        scan(x); scan(y); scan(v);
        a[x] = 1;
        b[y] = 1;
        if (m.find(x) == m.end()) {
            m[x].reserve(101);
            m[x][y] = v;
        }
        else if (m[x].find(y) == m[x].end())
            m[x][y] = v;
        else
            m[x][y] += v;
    }
    for (i = 0; i < q; i++) {
        list<long long> xFound;
        list<long long> yFound;
        long long r, c, res = 0;
        scan(r); scan(c);
        for (int j = 0; (r & ((1LL << j) - 1)) != r; j++) {
            long long t = (r & ((1LL << j) - 1)) | (1LL << j);
            if (a.find(t) != a.end())
                xFound.push_back(t);
        }
        for (int j = 0; (c & ((1LL << j) - 1)) != c; j++) {
            long long t = (c&((1LL << j) - 1)) | (1LL << j);
            if (b.find(t) != b.end())
                yFound.push_back(t);
        }
        for (long long j : xFound) {
            unordered_map<long long, unordered_map<long long, long long>>::iterator it = m.find(j);
            for (long long k : yFound) {
                unordered_map<long long, long long>::iterator it1 = it->second.find(k);
                if (it1 != it->second.end())
                    res += it1->second;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
