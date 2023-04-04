#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void solve(){
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(n + 1);
	int ans = 0;
	for (auto &it : a) {
		cin >> it;
		++cnt[it];
	}
	for (int l = 0; l < n; ++l) {
		int sum = 0;
		for (int r = l; r < n; ++r) {
			sum += a[r];
			if (l == r) continue;
			if (sum <= n) {
				ans += cnt[sum];
				cnt[sum] = 0;
			}
		}
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
