#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
int dp[N][2];

void solve(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) 
		cin >> a[i];

	vector<int> G[n];

	for(int i = 0 ; i < n - 1; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}


	function <void(int,int)> dfs = [&](int now ,int fa){
		dp[now][1] = a[now];
		for(auto x : G[now]){
			if(x == fa) continue;
			dfs(x,now);
			dp[now][1] += dp[x][0];
			dp[now][0] += max(dp[x][1],dp[x][0]);
		}
	};

	dfs(0,-1);

	cout << max(dp[0][0],dp[0][1]) << endl;
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