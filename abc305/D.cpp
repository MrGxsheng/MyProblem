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

	vector<LL> d(n);
	for(int i = 1 ; i < n  ; i++){
		if(i & 1 ){
			d[i] = d[i - 1];
		}else{
			d[i] = d[i - 1] + a[i] - a[i - 1];
		} 
	}

	cin >> m;
	while(m--){
		int l,r;
		cin >> l >> r;
		LL ans = 0;
		int idx = lower_bound(a.begin(), a.end(),l) - a.begin();
		int idx1 = lower_bound(a.begin(), a.end(),r) - a.begin();

		if(idx & 1){
			l = idx;
		}else {
			ans += a[idx] - l;
			l = idx;
		}

		if(idx1 & 1){
			r = idx1 - 1;
		}else{
			ans += r - a[idx1 - 1];
			r = idx1 - 1;
		}


		ans += d[r] - d[l];
		cout << ans << endl;
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