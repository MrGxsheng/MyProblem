#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k;
LL dp[10][100][2000];
void solve(){
	cin >> n >> k;
	vector<int> vis;
	for(int s = 0 ; s < (1 << n) ; s++){
		if((((s << 1) | (s >> 1)) & s) == 0) vis.push_back(s);
	}

	dp[0][0][0] = 1;
	for(int i = 1 ; i <= n ; i++)
		for(int l = 0 ; l < vis.size() ; l++){
			int s1 = vis[l];
			for(int r = 0 ; r < vis.size() ; r++){
				int s2 = vis[r];
				if(((s2 | (s2 << 1) | (s2 >> 1)) & s1) == 0){
					for(int j = 0 ; j <= k ; j++)
						if(j - __builtin_popcount(s1) >= 0)
							dp[i][j][s1] += dp[i - 1][j - __builtin_popcount(s1)][s2];
				}
			}
		}

	LL ans = 0;
	for(int i = 0 ; i < vis.size() ; i++) ans += dp[n][k][vis[i]];
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