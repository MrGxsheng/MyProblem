#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<vector<int>> dp(n,vector<int>(n));
	dp[0][0] = 1;
	for(int i = 1 ; i < n ; i++)
		for(int j = 0 ; j <= i ; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
		}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <= i ; j++){
			cout << dp[i][j] << ' ';

		}
		cout << endl;
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