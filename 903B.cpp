#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, a1, c1;scanf("%d %d %d", &h1, &a1, &c1);
    int h2,a2;scanf("%d %d", &h2, &a2);
    vector<int> res;
//    cout << "a1="<<a1<<endl;
    while(h2>0){
//        cout << h1<<" "<<h2<<endl;
        if(h2-a1<=0){
//            cout << "kusth"<<endl;
            res.push_back(1);
            h2-=a1;
            break;
        }else if(a2>=h1){
            res.push_back(0);
            h1+=c1;
        }else{
            res.push_back(1);
            h2-=a1;
        }
        h1-=a2;
    }
    printf("%d\n", res.size());
    for(int i:res)
        if(i==0)
        printf("HEAL\n");
    else printf("STRIKE\n");
}
