#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int ans = 0;
		for(int j = 0 ; j < 7 ; j++){
			int x;
			cin >> x;
			ans += x;
		}
		cout << ans << ' ';
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