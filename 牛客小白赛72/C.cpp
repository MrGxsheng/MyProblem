#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];

	LL cnt1 = 0;
	LL cnt2 = 0;

	for(int i = 0 ; i < n ; i++){
		if(a[i] - b[i] >= 0) cnt1 += a[i] - b[i];
		else cnt2 += a[i] - b[i];
	}

	if(cnt1 + cnt2 == 0){
		cout << cnt1 << endl;
	}else{
		cout << -1 << endl;
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