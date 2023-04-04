#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;

	vector<LL> a(n),s(n + 1),us(n + 2);
	map<LL,int> mp;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) s[i + 1] = s[i] + a[i];
	for(int i = n ; i >= 1 ; i--){
		us[i] = us[i + 1] + a[i - 1];
		mp[us[i]] = i;
	}

	LL ans = 0;
	for(int i = 1 ; i <= n; i ++) {
		if(mp[s[i]] && i < mp[s[i]]) ans = i + n - mp[s[i]] + 1;
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