#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];
bool vis[N];


void solve(){
	cin >> n >> m;
	vector<PII> a(n);
	for(int i = 0 ; i < n ; i++){
		int x,y;
		cin >> x >> y;
		a[i] = {x,y};
	}

	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < n ; j++){
			int x = a[i].first - a[j].first;
			int y = a[i].second - a[j].second;
			if(x * x + y * y <= m * m){
				G[i].push_back(j);
			}
		}

	function <void(int,int)> dfs = [&] (int now,int fa){
		if(vis[now]) return;
		vis[now] = true;
		for(auto x : G[now]){
			if(x == fa) continue;
			dfs(x,now);
		}
	};

	dfs(0,-1);

	for(int i = 0 ; i < n ; i++)
		if(vis[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
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