/**
 * 树形dp 真的好难啊
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 210;
int n,m;
int a[N],dp[N][N],tmp[N];
vector<int> edge[N];

void dfs(int u , int fa){
	dp[u][0] = a[u];
	for(auto v : edge[u]){
		if(v == fa) continue;
		dfs(v,u);
		for(int i = 0 ; i <= n ; i++) tmp[i] = dp[u][i];
		for(int i = 0 ; i <= n ; i++) 
			for(int j = max(m - i,0) ; j <= n ; j++)
				tmp[min(i,j + 1)] = max(tmp[min(i,j + 1)],dp[u][i] + dp[v][j]);
		for(int i = 0 ; i <= n ; i++) dp[u][i] = tmp[i];
	}
}

void solve(){
	cin >> n >> m;
	int maxn = 0;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i < n ; i++){
		int u,v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(1,0);

	for(int i = 0 ; i <= n ; i++) maxn = max(maxn,dp[1][i]);
	cout << maxn << endl;
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