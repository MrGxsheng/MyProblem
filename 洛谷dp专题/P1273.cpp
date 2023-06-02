#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 3010;
int n,m;
int dp[N][N];
void solve(){
	cin >> n >> m;
	vector<PII> G[n + 1];
	memset(dp,~0x3f,sizeof dp);
	for(int i = 1 ; i <= n - m ; i++){
		int k;
		cin >> k;
		for(int z = 0 ; z < k ; z++){
			int v,w;
			cin >> v >> w;
			G[i].push_back({v,w});
		}
	}

	vector<int> a(n + 1);
	for(int i = n - m + 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) dp[i][0] = 0;

	function <int(int,int)> dfs = [&](int now, int fa){
		if(now > n - m) {
			dp[now][1] = a[now];
			return 1;
		}
		int sum = 0;
		for(auto [x,w] : G[now]){
			if(x == fa) continue;
			int tk = dfs(x,now);
			vector<int> t(sum + 1);
			for(int j = 0 ; j <= sum ; j++) t[j] = dp[now][j];
			for(int j = 0 ; j <= sum ; j++)
				for(int k = 0 ; k <= tk ; k++)
					dp[now][j + k] = max(dp[now][j + k],t[j] + dp[x][k] - w);
			sum += tk;
		}
		return sum;
	};

	dfs(1,-1);

	for(int i = m ; i > 0 ;i--)
		if(dp[1][i] >= 0){
			cout << i << endl;
			return;
		}

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