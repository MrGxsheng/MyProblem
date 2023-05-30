#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 400000;
int n,m;
int dp[N * 2 + 20];
void solve(){
	cin >> n;
	vector<int> s(n + 1),f(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> s[i] >> f[i];

	memset(dp,-0x7f,sizeof dp);
	dp[N] = 0;
	
	for(int i = 1 ; i <= n ; i++){
		if(s[i] > 0)
			for(int j = N * 2 ; j >= s[i] ; j--)
				dp[j] = max(dp[j],dp[j - s[i]] + f[i]);
		else 
			for(int j = 0 ; j <= N * 2 + s[i] ; j++)
				dp[j] = max(dp[j],dp[j - s[i]] + f[i]); //负数要正着做DP，因为他是从左往右进行转移的
	}
	int ans = 0;
	for(int i = N ; i <= N * 2 ; i++)
		if(dp[i] >= 0)
			ans = max(ans,i + dp[i] - N);
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}