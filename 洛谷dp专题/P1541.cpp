#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 42;
int n,m;
int dp[N][N][N][N];
void solve(){
	cin >> n >> m;
	vector<int> z(n);
	map<int,int> mp;
	for(int i = 0 ; i < n ; i++) cin >> z[i];
	for(int i = 0 ; i < m ; i++){
		int x;
		cin >> x;
		mp[x] ++;
	}

	dp[0][0][0][0] = z[0];

	for(int a = 0 ; a <= mp[1] ; a++)
		for(int b = 0 ; b <= mp[2] ; b++)
			for(int c = 0 ; c <= mp[3] ; c++)
				for(int d = 0 ; d <= mp[4] ; d++){
					int x = a + b * 2 + c * 3 + d * 4;
					if(a != 0)	dp[a][b][c][d] = max(dp[a][b][c][d] , dp[a - 1][b][c][d] + z[x]);
                    if(b != 0)  dp[a][b][c][d] = max(dp[a][b][c][d] , dp[a][b - 1][c][d] + z[x]);
                    if(c != 0)  dp[a][b][c][d] = max(dp[a][b][c][d] , dp[a][b][c - 1][d] + z[x]);
                    if(d != 0)	dp[a][b][c][d] = max(dp[a][b][c][d] , dp[a][b][c][d - 1] + z[x]);

				}
	cout << dp[mp[1]][mp[2]][mp[3]][mp[4]] << endl;

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