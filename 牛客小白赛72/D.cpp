#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
LL g[N][N];
LL dp[N][N];
LL udp[N][N];


void solve(){
	cin >> n >> m;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> g[i][j];
		
	
	memset(dp, -0x3f3f3f3f, sizeof dp);
	memset(udp, -0x3f3f3f3f, sizeof udp);
	dp[n][m] = g[n][m];
	udp[1][1] = g[1][1];

	for(int i = n; i >= 1; i --){
		for(int j = m; j >= 1; j --){
			dp[i-1][j] = max(dp[i-1][j], dp[i][j] + g[i-1][j]);
			dp[i][j-1] = max(dp[i][j-1], dp[i][j] + g[i][j-1]);
		}
	}

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++){
			udp[i + 1][j] = max(udp[i + 1][j],udp[i][j] + g[i + 1][j]);
			udp[i][j + 1] = max(udp[i][j + 1],udp[i][j] + g[i][j + 1]);
		}


	int T;
	cin >> T;
	int k;
	while(T--){
		cin >> k;
		vector<PII> g;
		LL ans = udp[n][m];
		for(int i = 0 ;i < k ; i++){
		 	int x,y;
		 	cin >> x >> y;
		 	g.push_back({x,y});
		}

		 for(auto x : g){
		 	for(auto z : g){
		 		if(x == z) continue;
		 		ans = max(ans,udp[x.first][x.second] + dp[z.first][z.second]);
		 	}
		 }

		 cout << ans << endl;

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