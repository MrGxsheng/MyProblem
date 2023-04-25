#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];
int dep[N],fa[N][17];

void dfs(int now,int f){
	fa[now][0] = f;
	dep[now] = dep[f] + 1;
	for(int i = 1 ; i <= 16 ; i++) fa[now][i] = fa[fa[now][i -1]][i - 1];

	for(auto x : G[now]){
		if(x == f) continue;
		dfs(x,now);
	}
}

int lca(int u , int v){
	if(dep[u] < dep[v]) swap(u,v);

	for(int k = 16 ; k >= 0 ; k--)
		if(dep[fa[u][k]] >= dep[v])
			u = fa[u][k];

	if(u == v) return u;

	for(int k = 16 ; k >= 0 ; k--)
		if(fa[u][k] != fa[v][k]){
			u = fa[u][k];
			v = fa[v][k];
		}

	return fa[u][0];
}

int dis(int u,int v){
	return dep[u] + dep[v] - dep[lca(u,v)] * 2;
}

void solve(){
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cin >> m;

	for(int i = 0 ; i < m ; i++){
		int x,y,a,b,k;
		cin >> x >> y >> a >> b >> k;
		int d1 = dis(a,b);
		int d2 = dis(a,x) + 1 + dis(b,y);
		int d3 = dis(a,y) + 1 + dis(b,x);

	

		if(k >= d1 && (k - d1) % 2 == 0) cout << "YES" << endl;
		else if(k >= d2 && (k - d2) % 2 == 0) cout << "YES" << endl;
		else if(k >= d3 && (k - d3) % 2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
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