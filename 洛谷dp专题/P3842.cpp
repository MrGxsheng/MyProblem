#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int inf = 1E9;
int n,m;
void solve(){
	cin >> n;
	vector<PII> a(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second;

	
	vector<vector<int>> dp(n + 1,vector<int>(2));
	dp[1][0] = a[1].second + a[1].second - a[1].first - 1;
	dp[1][1] = a[1].second - 1;

	for(int i = 2 ; i <= n ; i++){
		dp[i][0] = min(dp[i - 1][0] + abs(a[i - 1].first - a[i].second) + a[i].second - a[i].first + 1,dp[i - 1][1] + abs(a[i - 1].second - a[i].second) + a[i].second - a[i].first + 1);
		dp[i][1] = min(dp[i - 1][0] + abs(a[i - 1].first - a[i].first) + a[i].second - a[i].first + 1 , dp[i - 1][1] + abs(a[i - 1].second - a[i].first) + a[i].second - a[i].first + 1);
	}

	cout << min(dp[n][0] + n - a[n].first,dp[n][1] + n - a[n].second) << endl;
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