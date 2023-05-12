/**
 * gcd(a,b) = gcd(a,a + b)
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
	cin >> n >> m;
	vector<LL> c(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	map<set<int>,LL> mp;
	set<int> G[n + 1];
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		G[v].insert(u);
	} 

	for(int i = 1 ; i <= n ; i++)
		if(!G[i].empty()) mp[G[i]] += c[i];

	LL ans = 0;
	for(auto i : mp){
		if(ans) ans = gcd(ans,i.second);
		else ans = i.second;
	}

	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}