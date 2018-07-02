#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie((NULL));
    string s;
    int n;
    cin >>n>>s;
    for(char c:s)
        cnt[c-'a']++;
    sort(cnt,cnt+26);
    for(int i=0; i<26; i++)
    {
        int idx=i+1;
        while(cnt[i]>0)
        {
            if(cnt[idx]==0)
            {
                idx=i+1;
                if(cnt[idx]==0)
                {
                    printf("No");
                    return 0;
                }
            }
            else
            {
                cnt[i]--;
                cnt[idx]--;
                idx++;
            }
        }
    }
    printf("Yes");
}
