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

	sort(a.begin(), a.end());
	LL ans = a[0] * a[n - 1];
	ans = max(ans,a[0] * a[1]);
	ans = max(ans,a[n - 1] * a[n - 2]);

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