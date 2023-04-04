#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int n0,n1,n2;

	cin >> n0 >> n1 >> n2;
	if (n1 == 0) {
		if (n0 != 0) {
			cout << string(n0 + 1, '0') << endl;
		} else {
			cout << string(n2 + 1, '1') << endl;
		}
		return;
	}
	string ans;
	for (int i = 0; i < n1 + 1; ++i) {
		if (i & 1) ans += "0";
		else ans += "1";
	}
	ans.insert(1, string(n0, '0'));
	ans.insert(0, string(n2, '1'));
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