#include <bits/stdc++.h>
using namespace std;

int main() {
    clock_t start=clock();
	int seq[]={2,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for(int i=0;i<15;i++){
        cout << seq[i]<<endl;
        string ans;cin >>ans;
        if(ans=="NO"){
            while((clock()-start)<CLOCKS_PER_SEC/10*i);
            exit(0);
        }
	}
}
