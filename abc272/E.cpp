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
	vector<vector<int>> f(m);
	for(int i = 0 ; i < n ; i++){
		int L = max((-a[i] + i) / (i + 1),1);
		int R = min((n - a[i] + i) / (i + 1),m + 1);

		for(int j = L - 1 ; j < R - 1 ; j++){
			f[j].push_back(a[i] + (i + 1) * (j + 1));
		}
	}

	for(int i = 0 ; i < m ; i++){
		int k = f[i].size();
		vector<int> cnt(k + 1);
		for(auto x : f[i])
			if(x < k)
				cnt[x]++;
		int ans = 0;
		while(cnt[ans] > 0) ans++;
		cout << ans << endl;

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