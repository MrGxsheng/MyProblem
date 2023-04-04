#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m;
void solve(){
	cin >> n;
	int ans = 0;
	while(n){
	    if(n & 1) ans++;
	    n >>= 1;
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