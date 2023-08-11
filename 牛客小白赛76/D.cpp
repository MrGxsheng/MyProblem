#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
const int MOD = 998244353;

LL n,m;
void solve(){
	cin >> n;
    LL ans = 0;

    bool vis = false;
    for (int i = 0 ; i < n; i++) {
        LL x;
        cin >> x;
        if(x && x != 1 && (vis || ans * x > ans + x)) ans *= x;
        else ans += x;
        if(ans > 2) vis = true;
        ans %= MOD;
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