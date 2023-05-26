#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int j = i;
		int cnt = 0;
		ans ++;
		while(j < n && a[j] + cnt <= m) {
			cnt += a[j];
			j++;
		}
		if(cnt) i = j - 1;
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