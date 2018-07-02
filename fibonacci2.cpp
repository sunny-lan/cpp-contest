#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

//#define MAXB 332193
#define MAXB 5

bitset<MAXB> bin;

template<size_t N>
void tobin(string& source, bitset<N>& out)
{
    string dest;
    for (auto c : source)
    {
        int tmp = c - '0';
        string str;
        while (tmp)
        {
            str += tmp % 2 + '0';
            tmp /= 2;
        }
        dest += str;
    }
    out = move(bitset<N>(dest));
}

int cornercase[] = { 0, 1, 1, 2 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string nm;
    cin >> nm;
    if(nm.length()==1)
    {
        int n=atoi(nm.c_str());
        if (n < 4)
        {
            printf("%d/n", cornercase[n]);
            return 0;
        }
    }
    tobin(nm, bin);
    cout <<bin<<endl;

    ull fcn = 0;
    ull fcnp1 = 1;

    ull f2cn;

    ull fnm1 = 0;
    ull fn = 1;
    ull fnp1;

    ull f2nm1;
    ull f2n;

    for(int bit=0; bit<MAXB; bit++)
    {
        fnp1 = fn + fnm1;

        if (bin[bit])
        {
            f2cn = (fn * fcnp1 + fnm1 * fcn ) % 1000000007;
            fcnp1 = (fnp1 * fcnp1  + fn * fcn ) % 1000000007;

            fcn = f2cn;
        }

        f2nm1 = (fn * fn  + fnm1 * fnm1 ) % 1000000007;
        f2n = (fn * fnp1  + fn * fnm1 ) % 1000000007;

        fnm1 = f2nm1;
        fn = f2n;
    }

    printf("%lu\n", fcn);
}
