#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> deg(n);
	vector<set<int>> e(n);

	int ans = n;
	for(int i = 0 ; i < m ; i++){
		int op,u,v;
		cin >> op;
		if(op == 1){
			cin >> u >> v;
			u--,v--;

			ans -= !deg[u]++;
			ans -= !deg[v]++;
			e[u].insert(v);
			e[v].insert(u);
		}else{
			cin >> u;
			u--;
			ans += (deg[u] > 0);
			deg[u] = 0;
			for(auto v : e[u]){
				ans += !--deg[v];
				e[v].erase(u);
			}
			e[u].clear();
		}
		cout << ans << endl;
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