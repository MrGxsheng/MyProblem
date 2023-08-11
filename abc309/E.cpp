#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 4e5 + 10;
vector<int> g[N],dd[N];
int son[N],vis[N],have[N];
int n,m;

void dfs(int u,int f,int mx){
	int nmx = mx - 1;
	for(auto vv : dd[u]) nmx = max(nmx,vv);
	if(nmx <= 0) return;
	for(auto x : g[u]){
		if(!vis[x]){
			vis[x] = have[x] = true;
			dfs(x,u,nmx);
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 2 ; i <= n ; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	}	

	for(int i = 1 ; i <= m ; i++){
		int p,d;
		cin >> p >> d;
		have[p] = true;
		dd[p].push_back(d);
	}

	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i] && have[i]) dfs(i,0,0);
	}

	for(int i = 1 ; i <= n ; i++) ans += have[i];
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