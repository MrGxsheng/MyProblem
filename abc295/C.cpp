#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);

	for(int i = 0 ; i < n ; i++) cin >> a[i];

	map<int,int> mp;

	for(int i = 0 ; i < n ; i++) mp[a[i]]++;

	int ans = 0;
	for(auto [x,y] : mp){
		ans += y / 2;
	}

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