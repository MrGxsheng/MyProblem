#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	bool st = false;
	int ans = 0;
	int id = -1 ;

	vector<int> a(n),b(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	
	for(int i = 0 ; i < n ; i++) {
		cin >> b[i];
		if(a[i] == m && b[i] > ans) {
			ans = b[i];
			id = i + 1;
		}
	}

	if(id != -1){
		cout << id << endl;
		return;
	}
	m = a[0];
	for(int i = 0 ; i < n ; i++) {
		// cin >> b[i];
		if(a[i] == m && b[i] > ans) {
			ans = b[i];
			id = i + 1;
		}
	}
	cout << id << endl;
	
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