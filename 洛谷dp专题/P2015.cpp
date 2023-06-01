#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
vector<PII> G[N];
int dp[150][150];
void solve(){
	cin >> n >> m;
	for(int i = 0 ; i < n - 1 ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}

	function <void(int,int)> dfs = [&](int now,int fa){
		for(auto [x,w] : G[now]){
			if(x == fa) continue;
			dfs(x,now);
			for(int j = m ; j ; j--)
				for(int k = j - 1 ; k >= 0 ; k--)
					dp[now][j] = max(dp[now][j],dp[now][j - k - 1] + dp[x][k] + w);
		}
	};
	dfs(1,-1);
	cout << dp[1][m] << endl;

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