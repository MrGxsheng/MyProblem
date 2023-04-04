#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	if (n < 4) {
		cout << -1 << endl;
		return;
	}
	for (int i = n; i >= 1; --i) {
		if (i & 1) cout << i << " ";
	}
	cout << 4 << " " << 2 << " ";
	for (int i = 6; i <= n; i += 2) {
		cout << i << " ";
	}
	cout << endl;
}	


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}