#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	 cin >> n >> m;
	 vector<bool> vis(n);

	 auto dfs = [&](auto self,int x) -> void{
	 	vis[x] = true;
	 	if(x == n - 1) exit(0);
	 	int k;
	 	cin >> k;

	 	vector<int> a(k);
	 	for(int i = 0 ; i < k ; i++){
	 		cin >> a[i];
	 		a[i]--;
	 	}

	 	for(auto y : a){
	 		if(!vis[y]){
	 			cout << y + 1 << endl;
	 			self(self,y);
	 			cout << x + 1 << endl;
	 			cin >> k;
	 			for(int i = 0 ; i < k ; i++){
	 				cin >> a[i];
	 				a[i]--;
	 			}
	 		}
	 	}
	 };
	 dfs(dfs,0);
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