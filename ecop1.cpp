#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main(){
    freopen("C:\\Users\\Sunny\\Desktop\\DATA31.txt", "r", stdin);
    for(int testcase=0;testcase<10;testcase++){
        int n,x,y,z;
        cin >>n>>x>>y>>z;
        vector<string> res;
        for(int i=0;i<n;i++){
            string s;cin  >>s;
            string crs;
            for(char c:s){
                int num=c-'0';
                if(num==0){
                    crs+=to_string(z);
                }else{
                    if(num%2==0){
                        crs+=to_string(num+x);
                    }else{
                        crs+=to_string(max(0, num-y));
                    }
                }
            }
            res.push_back(crs);
        }

        string tmp;cin>>tmp;
        vector<int> fail;
        for(int i=0;i<n;i++){
            string cur;cin >>cur;
            if(cur!=res[i]){
                fail.push_back(i);
            }
        }

        if(!fail.empty()){
            cout << "FAIL: ";
            for(int i=0;i<fail.size();i++){
                cout << fail[i]+1;
                if(i!=fail.size()-1)
                    cout <<",";
            }
            cout <<endl;

        }else{
            cout << "MATCH"<<endl;
        }
        cin >>tmp;
    }
}
