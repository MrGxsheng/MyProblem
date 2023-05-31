#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int inf = 0xfffff;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(2 * n + 1);
	vector<int> sum(2 * n + 1);
	vector dp(2 * n + 1,vector<int>(2 * n + 1,inf));
	vector zdp(2 * n + 1,vector<int>(2 * n + 1,-inf));
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1 ; i <= 2 * n ; i++){
		sum[i] = sum[i - 1] + a[i];
		dp[i][i] = 0;
		zdp[i][i] = 0;
	} 


	for(int len = 2 ; len <= n ; len++)
		for(int l = 1 ; l + len - 1 <= 2 * n ; l++){
			int r = l + len - 1;
			int x = sum[r] - sum[l - 1];
			for(int k = l ; k < r ; k++){
				dp[l][r] = min(dp[l][r],dp[l][k] + dp[k + 1][r] + x);
				zdp[l][r] = max(zdp[l][r],zdp[l][k] + zdp[k + 1][r] + x);
			}
		}
		
	int ans1 = inf , ans2 = -inf;
	for(int i = 1 ; i <= n ; i++){
		ans1 = min(ans1,dp[i][i + n - 1]);
		ans2 = max(ans2,zdp[i][i + n - 1]);
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
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