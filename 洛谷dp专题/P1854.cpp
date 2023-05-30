#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
int dp[N][N]; // 表示前i个花瓶中插j朵花的最优解
int a[N][N];
void solve(){
	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
			dp[i][j] = -2147483647;
		}

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			for(int k = i - 1 ; k <= j - 1 ; k++)
				dp[i][j] = max(dp[i][j],dp[i - 1][k] + a[i][j]);
	
	int ans = -2147483647;
	for(int i = n ; i <= m ;i++) ans = max(ans,dp[n][i]);
	cout << ans << endl;

	function <void(int,int)> dfs = [&](int x, int y){
		if(x > 0){
			int n = x;
			while(dp[x][n] != y) n++;
			dfs(x - 1,y - a[x][n]);
			cout << n << ' ';
		}
	};

	dfs(n,ans);
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