#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k;
void solve(){
	cin >> n >> m >> k;
	vector<vector<int>> adj(n);

	for(int i = 0 ; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	priority_queue<std::pair<int, int>> q;
	vector<int> dp(n,-1);

	for(int i = 0 ; i < k ; i++){
		int p,h;
		cin >> p >> h;
		p--;
		q.emplace(h,p);
	}

	while(q.size()){
		auto [d,x] = q.top();
		q.pop();

		if(dp[x] != -1) continue;

		dp[x] = d;

		if(d > 0){
			for(auto y : adj[x]) q.emplace(d - 1,y);
		}
	}

	vector<int> ans;
	for(int i = 0 ; i < n ; i++) 
		if(dp[i] != -1) ans.push_back(i);

	cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] + 1 << ' ';
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