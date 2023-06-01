#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010 , M = 300000;
int n,m;
vector<tuple<int,int,float>> G[N];
vector<tuple<int,int,float>> G1[N];
int cnt[N];
int in[N];
bool vis[N];
int ans[N];
int res;

bool in_stk[N];
int dfn[M],low[N],timestamp,stk[N],top;
int id[N],scc_cnt,Siz[N];
void tarjan(int u){
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u,in_stk[u] = true;
	for(auto [x,w,p] : G[u]){
		if(x == u) continue;
		if(!dfn[x]){
			tarjan(x);
			low[u] = min(low[u],low[x]);
		}else if(in_stk[x]) low[u] = min(low[u],dfn[x]);
	}

	if(dfn[u] == low[u]){
		++ scc_cnt;
		int y;
		do{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			Siz[scc_cnt] ++;
		}while(y != u);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int u,v,w;
		float p;
		cin >> u >> v >> w >> p;

		G[u].push_back({v,w,p});
	}

	int start;
	cin >> start;
	for(int i = 1 ; i <= n ; i++)
		if(!dfn[i])
			tarjan(i);

	for(int i = 1 ; i <= n ; i++)
		for(auto [x,w,p] : G[i]){
			if(id[i] == id[x]){
				while(w != 0){
					cnt[id[i]] += w;
					w = (int) ((p) * w);
				}
			}else {
				G1[id[i]].push_back({id[x],w,p});
				in[id[x]]++;
			}
		}
		
	queue<int> q;
	for(int i = 1 ; i <= scc_cnt ; i++){
		if(!in[i]) q.push(i); 
	}
	ans[id[start]] = cnt[id[start]];
	vis[id[start]] = 1;
	res = ans[id[start]];
	while(q.size()){
		int t = q.front();
		q.pop();	
		for(auto [x,w,p] : G1[t]){
			if(x == t) continue;

			if(--in[x] == 0){
				q.push(x);
			}
			if(vis[t]){
				ans[x] = max(ans[x],ans[t] + w + cnt[x]);
				res = max(res,ans[x]);
				vis[x] = true;
			}
		}
	}

	if(scc_cnt == 1) cout << ans[1] << endl;
	else cout << res << endl;
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