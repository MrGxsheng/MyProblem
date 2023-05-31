#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> dp(32);

	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		int maxx = 0;
		for(int k = 0 ; k <= 30 ; k++)
			if((1 << k) & x) maxx = max(maxx,dp[k] + 1);

		for(int k = 0 ; k <= 30 ; k++)
			if((1 << k) & x) dp[k] = maxx;
	}
	cout << *max_element(dp.begin(),dp.end()) << endl;
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