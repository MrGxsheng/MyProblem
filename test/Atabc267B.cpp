#include<bits/stdc++.h>
using namespace std;
#define int long long 
#pragma GCC optimize(3)
typedef pair<int,int>PII;
#define pb push_back
const int N  = 15;
bool st[N];
vector<int>v[10];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){//判断小球是否击倒
        if(s[i]=='1')st[i+1]=true;
        else st[i+1]=false;
    }
    if(st[1]){//如果小球1站立
        cout<<"No"<<endl;
        exit(0);
    }
    //从左到右每一列依次存入
    v[1].pb(7);
    v[2].pb(4);
    v[3].pb(8);
    v[3].pb(2);
    v[4].pb(5);
    v[4].pb(1);
    v[5].pb(9);
    v[5].pb(3);
    v[6].pb(6);
    v[7].pb(10);
    int l=1,r=7;//找到左右区间
    for(int i=1;i<=7;i++){
        l=i;
        for(auto x:v[i]){
            if(st[x])goto GG;
        }
    }
    GG:;
    for(int i=7;i>=1;i--){
        r=i;
        for(auto x:v[i]){
            if(st[x])goto GG2;
        }
    }
    GG2:;
    //l和r表示最左端和最右端
    if(l>r-2){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=l+1;i<r;i++){//判断中间是否出现全黑球的一列
        bool ok = true;
        for(auto x:v[i])if(st[x])ok=false;
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}