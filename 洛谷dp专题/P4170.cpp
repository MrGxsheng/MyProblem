#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int inf = 1E8;
int n,m;
void solve(){
	string s;
	cin >> s;

	n = s.size();
	s = '?' + s;
	vector dp(n + 1,vector<int>(n + 1,inf));
	for(int i = 1 ; i <= n ; i++) dp[i][i] = 1;
	for(int len = 2 ; len <= n ; len++)
		for(int l = 1 ; l + len - 1 <= n ; l++){
			int r = l + len - 1;
			if(s[l] == s[r]) dp[l][r] = min(dp[l + 1][r],dp[l][r - 1]); // 直接一笔刷成是s[l]的颜色再最优图里面的
			else
				for(int k = l ; k < r ; k++) // 不一样直接合并
					dp[l][r] = min(dp[l][r],dp[l][k] + dp[k + 1][r]);
		}
	cout << dp[1][n] << endl;
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