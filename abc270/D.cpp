#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> a(m);
	for(int i = 0 ; i < m ; i++) cin >> a[i];

	vector<int> dp(n + 1);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j < m && a[j] <= i ; j++)
			dp[i] = max(dp[i],i - dp[i - a[j]]);
		// dp[n] = max{ai + (n - a[i]) - dp[n - a[i]] | a[i] < n}
		// dp[i] 代表拥有i个石头，第一个玩家可以移除的石头数量
		// 如果第一个玩家移除a[i]个石头 那么 他最终移除 a[i] + 第二个人可以移除的石头数量
		// 第二个人的石头数量 = 第一个人选取剩下的石头减去 第一个人 在总共 i - a[i] 获取的最大数量
	cout << dp[n] << endl;
	
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