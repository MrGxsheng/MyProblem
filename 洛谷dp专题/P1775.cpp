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
	vector dp(n + 1,vector<int>(n + 1,inf));
	vector<int> sum(n + 1);
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		sum[i] = sum[i - 1] + x;
		dp[i][i] = 0;
	}

	for(int len = 2; len <= n ; len++){
		for(int i = 1 ; i + len - 1 <= n ; i++){
			int j = i + len - 1;
			for(int k = i ; k < j ; k++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
		}
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