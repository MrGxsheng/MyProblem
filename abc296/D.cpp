#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
LL lim = 9e18;
void solve(){
	cin >> n >> m;
	LL ans = lim;
	for(int i = 1 ; i <= 3e7 ; i++){
		LL v = m / i;
		if(m % i) v++;
		if(i > n || v > n) continue;
		if(1ll * v * i >= m){
			ans = min(ans,1ll * v * i);
		}
	}
	if(ans == lim) cout << -1 << endl;
	else cout << ans << endl;
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