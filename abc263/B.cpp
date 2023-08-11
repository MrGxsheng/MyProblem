#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
int fa[N];
vector<int> p[N];

void dfs(int x,int cnt){
	if(x == n - 1) {
		cout << cnt << endl;
		return;
	}

	for(auto z : p[x]){
		dfs(z,cnt + 1);
	}
}

void solve(){
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		cin >> fa[i];
		fa[i]--;
		
		p[fa[i]].push_back(i);
	}
	
	 dfs(0,0);
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