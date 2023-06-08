#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> t(n),x(n),a(n);
	for(int i = 0 ; i < n ; i++) cin >> t[i] >> x[i] >> a[i];

	vector<LL> dp(n);
	LL ans = 0;
	for(int i = 0 ; i < n ; i++) {
		if(x[i] > t[i]) continue;
		for(int j = max(0,i - 8) ; j < i ; j++)
			if(abs(x[i] - x[j]) <= t[i] - t[j])
				dp[i] = max(dp[j],dp[i]);
		dp[i] += a[i];
		ans = max(ans,dp[i]);
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