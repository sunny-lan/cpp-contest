#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\DATA11.txt", "r", stdin);
	for(int testcase = 0; testcase < 10; testcase++) {
            int T,N;
        cin>>T>>N;
        string c;
        int delay = 0;
        for(int i = 0 ; i<N;i++){
            cin>>c;
            if(c=="B"){
                delay+=T;
            }
            delay=delay==0?0:delay-1;
        }
        cout<<delay<<endl;
	}
}
