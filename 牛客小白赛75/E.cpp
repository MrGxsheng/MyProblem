#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int mod = 1000000007;
int dp[2005][2005];
int n,m;
void solve(){
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= 2000 ; j++)
        {
            if(!dp[i - 1][j]) continue;
            int L = (j * (i - 1) + i) / i;
            int R = (j * (i - 1) + m) / i;
            if(L <= R) {
                dp[i][L] += dp[i - 1][j];
                dp[i][R + 1] -= dp[i - 1][j];
            }
        }
        for(int j = 1 ; j <= 2000 ; j++){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
        dp[i][0] %= mod;
    }
    int ans = 0;
    for(int i = 0 ; i <= 2000 ; i++) ans = (ans + dp[n][i]);
    cout << (ans % mod + mod) % mod << "\n";
}

signed  main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}