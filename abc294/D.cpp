#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	map<int,int> mp;
	int cnt = 0;
	int ans = 1;
	while(m--){
		int op,x;
		cin >> op;
		if(op == 1){
			cnt++;
		}else if(op == 2){
			cin >> x;
			mp[x] = 1;
			while(mp[ans]) ans++;
		}else {
			cout << ans <<  endl;
		}
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