#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> cnt(n);
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		x = (x - i + n) % n;
		ans = max(ans,++cnt[x]);
		ans = max(ans,++cnt[(x + 1) % n]);
		ans = max(ans,++cnt[(x + n - 1) % n]);
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