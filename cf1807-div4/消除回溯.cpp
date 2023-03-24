#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int n,m;
int f[N][N];
int v[N],w[N]; // 物品体积，物品价值
int ansdfs,ansdp;
int ans;
void dfs(int u , int x ){
	if(u == n + 1){
		ansdfs = max(ansdfs,ans);
		return;
	}

	//选
	if(x >= v[u]){
		ans += w[u];
		dfs(u + 1,x - v[u]);
		ans -= w[u]; // 回溯
	}

	//不选
	dfs(u + 1,x);
}

void dp(){
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if(j>=v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
        }
    }
}

void solve(){
	// 物品个数  背包体积
	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++) cin >> v[i] >> w[i];

	dp();
	dfs(1,m,0);
	cout << "dfs: " << ansdfs <<  endl;
	cout << "dp: " << ansdp <<  endl;

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

