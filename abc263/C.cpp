#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void dfs(int pre, int cnt,vector<int> ans){
	if(cnt == n){
		for(int i = 0 ; i < n ; i++) cout << ans[i] << ' ';
		cout << endl;
		return;
	}

	for(int i = pre + 1 ; i <= m ; i++){
		ans.push_back(i);
		dfs(i,cnt + 1,ans);
		ans.pop_back();
	}
}

void solve(){
	cin >> n >> m;
	vector<int> ans;
	dfs(0,0,ans);
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