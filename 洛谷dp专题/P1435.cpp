#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> s;

	n = s.size();
	s = '?' + s;
	vector dp(n + 1 , vector<int>(n + 1));
	// i - j 之间的字符是回文的
	for(int k = 1 ; k < n ; k++)
		for(int i = 1 ; i <= n - k ; i++){
			int j = i + k;
			if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
			else dp[i][j] = min(dp[i + 1][j],dp[i][j - 1]) + 1;
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