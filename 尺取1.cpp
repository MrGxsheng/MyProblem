#include<bits/stdc++.h>
using namespace std;
int v[256];
string s;
int main(){
    cin>>s;
    int ss=26,k=0;
    int l=0,r=-1,ans=1e9,len=s.length();
    while(l<len)
    {
        while(r<len-1&&k<ss)
        {///右指针右移
            v[s[++r]]++;
            if(v[s[r]]==1) ++k;
        }
        if(k==ss) ans=min(ans,r-l+1);///达到条件
        if(v[s[l]]==1)k--;
        v[s[l++]]--;///左指针右移
    }
    cout<<ans<<endl;
    return 0;
}