#include <bits/stdc++.h>
using namespace std;

char mp[]="Ol2EASG7Bg";

int main() {
	string in;cin >>in;
	for(char c:in)
        if(c>='0' && c<='9')
        printf("%c", mp[c-'0']);
    else
        printf("%c", c);
}
