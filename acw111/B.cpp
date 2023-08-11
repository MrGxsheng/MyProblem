#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];

bool check(int x){
	int cnt = 1;
	LL last = a[0] + x;
	for(int i = 0 ; i < n ; i++){
		if(last + x >= a[i]) continue;
		last = a[i] + x;
		cnt++;
	}
	if(cnt <= 3 && last + x >= a[n - 1]) return true;
	return false;
}


void solve(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		a[i] *= 2;
	} 
	sort(a, a + n);
	double l = 0 , r = 2e9;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << fixed << setprecision(6);
	cout << r / 2.0 << endl;

	vector<double> res;
	double last = a[0] + r;
	res.push_back(last / 2.0);
	for(int i = 0 ; i < n ; i++){
		if(a[i] <= last + r) continue;
		last = a[i] + r;
		res.push_back(last / 2.0);
	}

	while(res.size() < 3) res.push_back(0);
	for(int i = 0 ; i < 3 ; i++) cout << res[i] << ' ';

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