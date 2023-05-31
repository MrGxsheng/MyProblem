#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int inf = 1E8;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n + 1);
	vector dp(n + 1,vector<int>(n + 1,inf));

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		dp[i][i] = 1;
	}

	for(int i = 1 ; i < n ; i++) dp[i][i + 1] = 1 + (a[i] != a[i + 1]);

	for(int len = 3 ; len <= n ; len++)
		for(int l = 1 ; l + len - 1 <= n ; l++){
			int r = l + len - 1;
			if(a[l] == a[r]) dp[l][r] = dp[l + 1][r - 1];
			for(int k = l ; k < r ; k++) dp[l][r] = min(dp[l][r],dp[l][k] + dp[k + 1][r]);
		}
	cout << dp[1][n] << endl;
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