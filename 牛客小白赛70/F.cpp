#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 200010;
int n,m,k;
vector<int> adj[N];
int dp[N][51],siz[N],ndp[51];

void dfs(int now, int fa){
	for(auto x : adj[now]){
		if(x == fa) continue;
		dfs(x,now);
		siz[now] += siz[x];
		memset(ndp,0x3f,sizeof ndp);
		for(int i = 0 ; i <= m ; i++)
			for(int j = 0 ; j <= siz[x] && i + j <= m ; j++){
				int w = j != siz[x];
				ndp[i + j] = min(ndp[i + j],dp[now][i] + dp[x][j] + w);
			}
		swap(ndp,dp[now]);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i < n ; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	cin >> k;
	for(int i = 0 ; i < k ; i++) {
		int x;
		cin >> x;
		siz[x]++;
	}

	dfs(1,0);
	int ans = 2e9;
	for(int i = 0 ; i <= m ; i++) ans = min(ans,dp[1][i] * 2);
	cout << ans << endl;
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