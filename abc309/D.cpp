#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> e[N];
const int inf = 0x3f3f3f3f;
void solve(){
	int n1,n2;
	cin >> n1 >> n2 >> m;
	vector<int> dist1(n1,inf);
	vector<int> dist2(n1 + n2,inf);

	auto bfs = [&](vector<int> &dis,int st){
		vector<bool> vis(n1 + n2);
		dis[st] = 0;
		queue<int> q;
		q.push(st);
		while(q.size()){
			auto t = q.front();
			q.pop();

			vis[t] = true;
			for(auto u : e[t]){
				if(dis[u] > dis[t] + 1){
					dis[u] = dis[t] + 1;
					if(!vis[u]){
						vis[u] = true;
						q.push(u);
					}
				}
			}
		}
	};


	while(m--){
		int u,v;
		cin >> u >> v;
		u--,v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int mx1 = 0;
	int mx2 = 0;
	bfs(dist1,0);
	bfs(dist2,n1 + n2 - 1);

	for(int i = 0 ; i < n1 ; i ++)
		if(dist1[i] != inf) mx1 = max(mx1,dist1[i]);

	for(int i = n1 ; i < n1 + n2 ; i++)
		if(dist2[i] != inf) mx2 = max(mx2,dist2[i]);
	cout << mx1 + mx2 + 1 << endl;
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