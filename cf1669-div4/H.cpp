#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	map<int,int> mp;
	for(int i = 0 ; i < n ; i++){
		int x = a[i];
		for(int j = 0 ; j <= 30 ; j++){
			if((x >> j) & 1) mp[j]++;
		}
	}

	int ans = 0;
	for(int i = 30 ; i >= 0 ; i--){
		int need = n - mp[i];
		if(need <= m){
			m -= need;
			ans += (1 << i);
		}
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