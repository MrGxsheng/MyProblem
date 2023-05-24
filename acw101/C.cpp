#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
    vector<int> a(n);
    vector dp(n,vector<int>(2));
    for(int i = 0 ; i < n ; i++ ) cin >> a[i];

    //dp[i][0]:以第i个元素结尾，且最大值为 a[i]的最长连续子序列
    //dp[i][1]:以第i个元素结尾，且最小值为 a[i]的最长连续子序列
    dp[0][0] = 1;
    dp[0][1] = 1;
    int ans = 1;
    for(int i = 1 ; i < n ; i++){
        if (a[i] > a[i - 1]) {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = 1;
        } else if (a[i] == a[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        } else {
            dp[i][0] = 1;
            dp[i][1] = dp[i - 1][0] + 1;
        }
        ans = max({ans, dp[i][0], dp[i][1]});
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