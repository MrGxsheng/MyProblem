#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int dp[2];
void solve(){
	cin >> n;

	array<LL,2> dp{};
	for(int i = 0 ; i < n ; i++){
		int x,y;
		cin >> x >> y;
		if(x == 0) {
			dp[0] = max(dp[0],max(dp[0],dp[1]) + y);
		}else {
			dp[1] = max(dp[1],dp[0] + y);
		}
	}

	cout << max(dp[0],dp[1]) << endl;

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