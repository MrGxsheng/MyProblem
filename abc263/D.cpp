#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,l,r;
void solve(){
	cin >> n >> l >> r;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	LL ans = 1E18;
	LL s = 0 , mn = 1E18;
	for(int i = 0 ; i <= n ; i++){
		if(i > 0)
			s += a[i - 1];
		mn = min(mn,1ll * i * l - s);
		ans = min(ans,mn + 1ll * (n - i) * r + s);
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