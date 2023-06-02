#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];
void solve(){
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	for(int i = 1 ; i < n ; i++){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}

	vector<int> dp(n + 1);
	function <void(int,int)> dfs = [&](int now,int fa){
		dp[now] = a[now];
		for(auto x : G[now]){
			if(x == fa) continue;
			dfs(x,now);
			if(dp[x] > 0) dp[now] += dp[x];
		}
	};

	dfs(1,0);

	cout << *max_element(dp.begin() + 1, dp.end()) << endl;

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