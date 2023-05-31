#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(2 * n + 1);
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		a[i + n] = a[i];
	}

	vector dp(2 * n + 1 , vector<int>(2 * n + 1));

	for(int len = 2 ; len <= n + 1 ; len ++)
		for(int l = 1 ; l + len - 1 <= 2 * n ; l++){
			int r = l + len - 1;	
			for(int k = l + 1 ; k < r ; k++) // 特殊 全闭区间
				dp[l][r] = max(dp[l][r],dp[l][k] + dp[k][r] + a[l] * a[r] * a[k]);

		}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++) ans = max(ans,dp[i][i + n]);
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