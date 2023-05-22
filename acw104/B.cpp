#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;

void solve(){
	cin >> n >> m;
	LL ans = 0;
	for(LL i = 1 , k = 1 ; k <= 64 ; i = i << 1 | 1 , k++){
		for(LL j = 0 ; j < k - 1 ; j++){
			LL t = i ^ (1ll << j);
			ans += n <= t && t <= m;
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