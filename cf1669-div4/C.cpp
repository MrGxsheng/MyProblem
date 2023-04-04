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

	for(int i = 0 ; i < n; i ++) {
		cin >> a[i];
		a[i] %=2 ;
	}

	for(int i = 2 ; i < n ; i ++){
		if(a[i - 2] != a[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}