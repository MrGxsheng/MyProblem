#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int n,m;
void solve(){
	cin >> n >> m;
	vector<tuple<int,int,int>> a(m + 1);
	for(int i = 1 ; i <= m ; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		a[i] = {x,y,z};
	}

	vector<int> dp(m + 1,1);

	for(int i = 1 ; i <= m ; i++){
		auto [x,y,z] = a[i];
		for(int j = 1 ; j < i ; j++){
			auto [x1,y1,z1] = a[j];
			if(abs(y - y1) + abs(z - z1) <= abs(x - x1)){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= m ; i++) ans = max(ans,dp[i]);
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