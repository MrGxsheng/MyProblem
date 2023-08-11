#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 5010;
constexpr LL inf = 1E18;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++) cin >> v[i];

	vector<int> w(n + 1);
    for (int i = 0; i < m; i++) {
        int c, y;
        std::cin >> c >> y;
        w[c] = y;
    }
	vector<LL> dp(n + 1, -inf);
	dp[0] = 0;
	for(int i = 0 ; i < n ; i++){
		vector<LL> g(n + 1 , -inf);
		for(int x = 0 ; x <= i ; x++){
			g[x + 1] = max(g[x + 1],dp[x] + v[i] + w[x + 1]);
			g[0] = max(g[0],dp[x]);
		}
		dp = g;
	}
	cout << *std::max_element(dp.begin(), dp.end()) << endl;



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