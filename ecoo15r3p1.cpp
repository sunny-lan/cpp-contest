#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int test=0;test<10;test++){
        string num;cin >>num;
        reverse(num.begin(), num.end());
        int cdig=0;
        string res;
        while(!num.empty()){
            string ac;
            while(!num.empty()){
                string nxt=num[0]+ac;
                if(atoi(nxt.c_str())>cdig)
                    break;
                ac=nxt;
                num=num.substr(1);
            }
            if(ac.empty())
                res="0 "+res;
            else
                res=ac+" "+res;
            cdig++;
        }
        cout << res<<endl;
    }
}
