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
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	vector<int> dp(n + 1),udp(n + 1);
	dp[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		dp[i] = 1;
		for(int j = i ; j >= 1 ; j--){
			if(a[i] > a[j]) dp[i] = max(dp[i],dp[j] + 1);
		}
	}

	for(int i = n ; i >= 1 ; i--){
		udp[i] = 1;
		for(int j = i ; j <= n ; j++){
			if(a[i] > a[j]) udp[i] = max(udp[i],udp[j] + 1);
		}
	}

	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans,dp[i] + udp[i] - 1);
	}
	cout << n - ans<< endl;

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