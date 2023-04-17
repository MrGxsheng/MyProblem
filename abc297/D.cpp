#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	cin >> n >> m;
	if(n > m) swap(n,m);
	if(n == m){
		cout << 0 << endl;
		return;
	}

	LL ans = 0;

	LL x = (m - 1)  / n;
	ans += x;
	m -= x * n ;
// 	cout << m << ' ' << ans << endl;
	while(m != n){
		if(n == m){
			cout << ans << endl;
			return;
		}
		if(n < m) m -= n , ans++;
		else n -= m , ans++;
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