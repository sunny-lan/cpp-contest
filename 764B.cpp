#include <bits/stdc++.h>
using namespace std;

#define MAXN 2001

char res[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >>n>>s;
    vector<int> st, ptr;
    for(int i=n-1;i>=0;i--)
        st.push_back(i);

    while(!st.empty()){
        int med=st.size()/2;
        ptr.push_back(st[med]);
        st.erase(st.begin()+med);
    }

    for(int i=0;i<n;i++)
        res[ptr[i]]=s[i];

    printf("%s\n", res);
}
