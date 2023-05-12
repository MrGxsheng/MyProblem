#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];
int f[N];
vector<int> G[N];
int g[N];
void dfs(int now,int fa){
	f[now] = a[now];
	for(auto x : G[now]){
		if(x == fa) continue;
		dfs(x,now);
		f[now] += max(0,f[x]);
	}
}

void dfs2(int now , int fa){
	g[now] = f[now];
	g[now] += max(0,g[fa] - max(f[now],0));
	for(auto x : G[now]){
		if(x == fa) continue;
		dfs2(x,now);
	}
}

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		a[i] = (a[i] == 0) ? -1 : 1;
	}


	for(int i = 0 ; i < n -  1; i ++){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1,0);
	dfs2(1,0);
	for(int i = 1 ; i <= n ; i++){
		cout << g[i] << ' ';
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