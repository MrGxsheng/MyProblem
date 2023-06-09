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

	vector<LL> ans;
	for(int i = 0 ; i < n ; i++)
		if(a[i] > 0) ans.push_back(1ll * (n - i) * a[i]);
	sort(ans.rbegin(), ans.rend());

	LL res = 0;
	if(ans.size() <= m){
		cout << accumulate(a.begin(), a.end(),0ll) - accumulate(ans.begin(), ans.end(),0ll) << endl;
	}else{

		for(int i = 0 ; i < m ; i++) res += ans[i];
		cout << accumulate(a.begin(), a.end(),0ll) - res << endl;
	}

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}