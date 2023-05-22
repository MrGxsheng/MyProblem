#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<LL> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	vector<LL> f(n);
	
	for(int i = n - 2 ; i >= 0; i--){
		f[i] = max(a[i + 1],f[i + 1]);
	}

	for(int i = 0 ; i < n ; i++){
		cout << max(f[i] - a[i] + 1 * 1ll,0ll) << ' ';
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