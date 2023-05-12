#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,double> PII;
const int N = 1000010;
int n,m;
vector<PII> G[N];
double ans;
void dfs(int now ,int fa , double pp){
	if(now == n){
		cout << pp << endl;
		ans += pp;
		return;
	}

	for(auto x : G[now]){
		if(x.first == fa) continue;
		double p = x.second / 100;
		if(pp) dfs(x.first,now,pp * p );
		else dfs(x.first,now,p);
		

	}
}

void solve(){
	cin >> n >> m;

	for(int i = 0 ; i < m  ; i++){
		int x,y;
		double p;
		cin >> x >> y >> p;
		G[x].push_back({y,p});			
	}

	dfs(1,-1,0);

	cout << fixed << setprecision(6) << ans << endl;
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