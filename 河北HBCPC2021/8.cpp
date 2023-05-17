#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	cin >> n >> m;
	vector<LL> a(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];


	vector<LL> dp(n + 2);
	
	int l = 0 , r = n + 1;
	while(l < r){
		int mid = l + r + 1 >> 1;
		dp[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			dp[i] = dp[i - 1];
			if(i - mid >= 0 && i + mid <= n + 1)
				dp[i] = max(dp[i],dp[i - mid] + a[i]);
		}
		if(dp[n] >= m) l = mid;
		else r = mid - 1;
	}
	if(l == 0) cout << -1 << endl;
	else cout << l << endl;

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