#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
LL cnt[N];
void solve(){
	cin >> n;
	vector<LL> s(n + 1);
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	LL ans = 0;
	cnt[0] = 1;
	for(LL i = 1 ; i <= n ; i++){
		for(LL j = 0 ; j * j <= s[i] ; j++)
			ans += cnt[s[i] - j * j];
		cnt[s[i]]++;
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