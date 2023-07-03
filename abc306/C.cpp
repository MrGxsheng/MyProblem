#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(3 * n);
	for(int i = 0 ; i < 3 * n ; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<PII> ans(n);

	map<int,int> mp;
	for(int i = 0 ; i < 3 * n ; i++) {
		mp[a[i]]++;
		if(mp[a[i]] == 2) ans[a[i]] = {i,a[i]};
	}
	sort(ans.begin(), ans.end());


	for(int i = 0 ; i < n ; i++){
		cout << ans[i].second + 1 << ' ';
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