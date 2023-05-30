#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int dp[30][15][15];
int w[15][15];
void solve(){
	cin >> n;
 	int a,b,c;
    while(cin >> a >> b >> c, a || b || c) w[a][b] = c;

	for(int k = 2 ; k <= 2 * n ; k++)
		for(int i1 = 1 ; i1 <= n ; i1++)
			for(int i2 = 1 ; i2 <= n ; i2++){
				int j1 = k - i1 , j2 = k - i2;
				if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
					int &x = dp[k][i1][i2];
					int t = w[i1][j1];
					if(i1 != i2) t += w[i2][j2];
					x = max(x,dp[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x,dp[k - 1][i1][i2 - 1] + t);
					x = max(x,dp[k - 1][i1 - 1][i2] + t);
					x = max(x,dp[k - 1][i1][i2] + t);
				}
			}
	cout << dp[n * 2][n][n] << endl;


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