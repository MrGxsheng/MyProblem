#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n + 1);
	vector dp(59,vector<int>(n + 1));

	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		dp[a[i]][i] = i + 1;
	}
	
	int ans = 0;
	for(int i = 2 ; i <= 58 ; i++)
		for(int j = 1 ; j <= n ; j++){
			if(!dp[i][j]) dp[i][j] = dp[i - 1][dp[i - 1][j]];
			if(dp[i][j]) ans = i;
		}
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