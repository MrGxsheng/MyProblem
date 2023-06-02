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
	vector<int> G[n];
	for(int i = 1 ; i < n ; i++){
		int u,k;
		cin >> u >> k;
		for(int j = 0 ; j < k ; j++){
			int v;
			cin >> v;
			G[u].push_back(v);
		}
	}

	vector dp(n,vector<int>(n));

	function <void(int,int)> dfs = [&](int now,int fa){
		dp[now][1] = 1;
		for(auto x : G[now]){
			if(x == fa) continue;
			dfs(x,now);
			dp[now][0] += dp[x][1];
			dp[now][1] += min(dp[x][0],dp[x][1]);
		}
	};
	dfs(0,-1);
	cout << min(dp[0][1],dp[0][0]) << endl;

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