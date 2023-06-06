#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	LL k;
	cin >> n >> k;
	vector<LL> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	

	int cnt = n;

	auto v = a;
	sort(v.begin(), v.end());

	LL t = 0 , sum = 0;
	for(int i = 0 ; i < n ; i++){
		t = max(t,(k - sum) / (n - i));
		sum += v[i];
	}

	for(int i = 0 ; i < n ; i++){
		k -= min(t,a[i]);
		a[i] = max(0ll,a[i] - t);
	}

	for(int i = 0 ; i < n ; i++){
		if(k > 0 && a[i] > 0){
			a[i]--;
			k--;
		}
		cout << a[i] << ' ';
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