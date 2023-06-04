#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;

	for(int k = 0 ; k <= n ; k++){
		int res = k * (k - 1) / 2  + (n - k) * (n - k - 1) / 2;
		if(res == m){
			cout << "YES" << endl;
			for(int i = 0 ; i < n ; i++)
				cout << (i < k ? 1 : -1) << ' ';
			cout << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}