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
	int ans = 0; 
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			int x;
			cin >> x;
			if(!mp[x]) ans++;
			mp[x]++;
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