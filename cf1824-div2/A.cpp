#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int ans;
string s;

bool check(string x,int size){
	for(int i = 0 ,j = size - 1 ; i < j ; i++,j-- )
		if(x[i] != x[j]) return true;
	return false;
}

void dfs(int u,int len, string x){
	if(u == n && len > 2 && check(x,len)){
		ans = max(ans,len);
		return;
	}
	if(u == n) return;

	string t = x + s[u];
	dfs(u + 1,len + 1,t);
	dfs(u + 1,len,x);
}

void solve(){
	cin >> s;
	ans = 0;
	n = s.size();
	string a = "";
	dfs(0,0,a);
	if(!ans) {
	    cout << -1 << endl;
	    return;
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