#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using u64 = unsigned long long;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	u64 ans = 0;
	for(int i = 0 ; i <= 63 ; i++){
		u64 x;
		cin >> x;
		ans += 1ll * x << i;
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