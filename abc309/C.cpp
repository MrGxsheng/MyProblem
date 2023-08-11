#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<PII> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i].first >> a[i].second;

	LL sum = 0;
	sort(a.begin(), a.end());
	for(int i = 0 ; i < n ; i++){
		sum += a[i].second;
	}

	if(sum <= m){
		cout << 1 << endl;
		return;
	}

	LL ans = 1;
	int day = 0;
	for(int i = 0 ; i < n ; i++){
		sum -= 1ll *  a[i].second;

		if(sum <= m){
			cout << a[i].first + 1 << endl;
			return;
		}

		

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