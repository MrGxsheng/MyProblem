#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m,D;
void solve(){
	cin >> n >> m >> D;
	vector<LL> a(n),b(m);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < m ; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	LL ans = -1;
	for(int i = 0 ; i < n ; i++){
		auto it = upper_bound(b.begin(), b.end(),a[i] + D);
		if(it != b.begin()){
			LL z = *(it - 1);
			if(z >= a[i] - D)
				ans= max(ans,z + a[i]);
		}
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