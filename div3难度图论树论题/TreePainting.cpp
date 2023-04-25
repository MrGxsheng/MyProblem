/**
 * 换根dp
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 200010;
int n,m;
vector<int> G[N];
int siz[N];
LL f[N],g[N],ans;
void dfs(int now,int fa){
	siz[now] = 1;
	for(auto x : G[now]){
		if(x == fa) continue;
		dfs(x,now);
		siz[now] += siz[x];
		f[now] += f[x];
	}
	f[now] += siz[now];
}

void dfs2(int now,int fa){
	if(now != 1){
		g[now] = g[fa] + n - siz[now] * 2;
		ans = max(ans,g[now]);
	}

	for(auto x : G[now]){
		if(x == fa) continue;
		dfs2(x,now);
	}
}

void solve(){
	cin >> n;
	for(int i = 0 ; i < n - 1; i++){
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1,0);
	ans = g[1] = f[1];
	dfs2(1,0);

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