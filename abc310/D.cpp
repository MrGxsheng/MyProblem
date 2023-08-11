#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m,t;


void solve(){
	cin >> n >> t >> m;
	vector<int> a(m),b(m);
	for(int i = 0 ; i < m ; i++){
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
	}

	vector<int> c(n);
	int ans = 0;
	auto dfs = [&](auto self,int x ,int y) -> void{
		if(x == n){
			if(y != t)
				return;
			bool ok = true;
			for(int i = 0 ; i < m ; i++)
				if(c[a[i]] == c[b[i]])
					ok = false;
			ans += ok;
			return;
		}

		for(int i = 0 ; i <= y ; i++){
			c[x] = i;
			self(self,x + 1,max(y,i + 1));
		}
	};
	dfs(dfs,0,0);
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