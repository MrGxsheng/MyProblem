#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<PII> G[N];
double dp[N];
void solve(){

	/*
	分析:不妨设f[x]表示x点到终点的期望路径总长度
	显然有f[n]=0
	那么对于一条有向边,连接着x和y点(x->y)
	那么显然有f[x]=sigma(f[y]+w[i])/degree[x] 
	其中degree[x]表示x点的出度,w[i]表示这条边的边权 
	那么假设我们已经知道了f[y]
	我们就可以反推f[x]
	显然只需要反向建边之后跑个拓扑排序就行了
	那么最后答案即为f[1]
	时间复杂度O(n+m) 
	*/
	cin >> n >> m;
	vector<int> in(n + 1),dg(n + 1);
	for(int i = 1 ; i <= m ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		// 反向建图逆推
		G[v].push_back({u,w});
		in[u]++;
		dg[u]++;
	}

	queue<int> q;
	q.push(n);
	while(q.size()){
		auto x = q.front();
		q.pop();

		for(auto [z,w] : G[x]){
			if(x == z) continue;
			dp[z] += (dp[x] + w) / dg[z]; 
			if(--in[z] == 0){
				q.push(z);
			}
		}
	}

	cout << fixed << setprecision(2) << dp[1] << endl;
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