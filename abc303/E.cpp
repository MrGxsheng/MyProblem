#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;

	vector<vector<int>> adj(n);
	for(int i = 1 ; i < n ; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> a;
	function<int(int,int)> dfs = [&](int x,int p){
		int t = 0;
		for(auto y : adj[x]){
			if(y == p) continue;
			int v = dfs(y,x);
			if(v != 2){
				t = v + 1;
			}
		}
		if(t == 1){
			a.push_back(adj[x].size());
		}
		return t;
	};
	dfs(0,-1);

	sort(a.begin(), a.end());
	for(int i = 0 ; i < a.size() ; i++){
		cout << a[i] << " ";
	}
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