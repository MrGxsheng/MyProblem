#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int d[6][6]=
{
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};
void solve(){
	string s,ss;
	map<char,int> mp;
	mp['A'] = 1;
	mp['C'] = 2;
	mp['G'] = 3;
	mp['T'] = 4;
	cin >> n >> s >> m >> ss;

	vector<int> a(n + 1),b(m + 1);

	for(int i = 0 ; i < n ; i++)
		a[i + 1] = mp[s[i]];

	for(int i = 0 ; i < m ; i++)
		b[i + 1] = mp[ss[i]];

	vector dp(n + 1,vector<int>(m + 1));

	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i++) dp[i][0] = dp[i - 1][0] + d[a[i]][5];
	for(int i = 1 ; i <= m ; i++) dp[0][i] = dp[0][i - 1] + d[5][b[i]];

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			dp[i][j] = max({dp[i - 1][j - 1] + d[a[i]][b[j]] , dp[i - 1][j] + d[a[i]][5] , dp[i][j - 1] + d[5][b[j]]});

	cout << dp[n][m] << endl;
		
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