#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];
int dp[350][350];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		int u,w;
		cin >> u >> w;
		G[u].push_back(i);
		dp[i][1] = w;
	}
	function <void(int,int)> dfs = [&](int now, int fa){
		for(auto x : G[now]){
			if(now == fa) continue;
			dfs(x,now);
			for(int i = m + 1 ; i >= 1 ; i--)
				for(int j = i - 1 ; j >= 0 ; j--)
					dp[now][i] = max(dp[now][i],dp[x][j] + dp[now][i - j]);
		}
	};
	dfs(0,-1);
	cout << dp[0][m + 1] << endl;
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