#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int ans[N];
int q[N];
vector<int>h[N];
int sz[N];
long long dp[N];
long long lg[N];
int qmi(int a,int b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=(long long)a*a%mod;
        b>>=1;
    }
    return res;
}
void dfs(int u) {
    for (auto j : h[u]) {
        dfs(j);
        sz[u]+=sz[j];
        dp[u]=dp[u]*dp[j]%mod;
        dp[u]=dp[u]*qmi(lg[sz[j]],mod-2)%mod;
    }
    dp[u]=(dp[u]*lg[sz[u]-1])%mod;
}
int main() {
    lg[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        lg[i]=lg[i-1]*i%mod;
    }
    int T;
    cin >> T;
    long long he=0;
    long long res=1;
    for (int o = 0; o < T; o++) {
        int n;
        cin >> n;
        he+=n;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            sz[i] = 1;
            h[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int a;
            scanf("%d", &a);
            h[a].push_back(i);
        }
        dfs(1);
        res=res*dp[1]%mod;
        res=res*qmi(lg[n],mod-2)%mod;
//      cout<<dp[1]<<endl;
    }
    res=res*lg[he]%mod;
    cout<<res;
    return 0;
}