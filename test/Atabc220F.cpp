#include "bits/stdc++.h"
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10;
vector <PII> e[N];
long long f[N];
int siz[N],dep[N];
void dp1(int u,int fa)
{
    siz[u] = 1;
    for(auto x:e[u]) {
        int j = x.fi,w = x.se;
        if(j == fa) continue;
        dep[j] = dep[u] + 1;
        dp1(j,u);
        siz[u] += siz[j];
    }
}
void dp2(int u,int fa)
{
    for(auto x:e[u]) {
        int j = x.fi,w = x.se;
        if(j == fa) continue;
        f[j] = f[u] - 2 * siz[j] + siz[1];
        dp2(j,u);
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back({v,1});
        e[v].push_back({u,1});
    }
    dp1(1,0);
    for(int i = 1;i <= n;i++) f[1] += dep[i];
    dp2(1,0);
    for(int i = 1;i <= n;i++) cout << f[i] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T = 1;
    while(T --) {
        solve();
    }
    return 0;
}
/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/