#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int inf = -0x3f3f3f3f;
int n,m;
int q[N];
int h = 1,t;
void solve(){
	int L,R;
	cin >> n >> L >> R;
	vector<int> a(n + 1);
	for(int i = 0 ; i <= n ; i++) cin >> a[i];

	vector<int> dp(n + 1,inf);
	dp[0] = 0;
	int ans = inf;
	for(int i = L ; i <= n ; i++){
		while(h <= t && q[h] < i - R) h++; // 把不在范围的仍出去
		while(h <= t && dp[q[t]] < dp[i - L]) t--; // 把小于新的数的队尾扔出去
		q[++t] = i - L; // 加新数喽
		dp[i] = dp[q[h]] + a[i]; // 从最大值蹦
		if(i + R > n) ans = max(dp[i],ans);

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