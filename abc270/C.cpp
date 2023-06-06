#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int X,Y;
	cin >> n >> X >> Y;
	X--,Y--;
	vector<vector<int>> adj(n);

	for(int i = 0 ; i < n - 1; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> parent(n,-1);
	function <void(int)> dfs = [&](int x){
		if(x == X){
			while(x != -1){
				cout << x + 1 << ' ';
				x = parent[x];
			}
			return;
		}

		for(auto y : adj[x]){
			if(y == parent[x]) continue;
			parent[y] = x;
			dfs(y);
		}
	};
	dfs(Y);


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