#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	LL ans = 0;
	string s;
	cin >> s >> m;

	n = s.size();
	for(int i = 0 ; i < n ; i++)
		if(s[i] == '1') ans += 1ll << (n - 1 - i);

	if(m < ans){
		cout << -1 << endl;
		return;
	}

	for(int i = 0 ; i < n ; i++){
		if(s[i] == '?' && ans + (1ll << (n - 1 - i)) <= m){
			ans += (1ll << (n - 1 - i));
		}
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