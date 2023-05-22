#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
LL a[N];

bool check(LL x){
	if(x <= n)	return false;
	LL temp = m, cnt = 0;	x -= n;
	for(int i = 0; i < n && x > 0; i ++){
		if(x + 1 >= a[i]){
			if(a[i] & 1){
				x = x - a[i] + 1;
				temp -= a[i] / 2;
			}
			else{
				cnt ++;
				x = x - a[i] + 2;
				temp -= (a[i] - 1) / 2;
			}
		}
		else{
			temp -= (x + 1) / 2;
			x = 0;
		}
		if(temp <= 0)	return true;
	}
	if(temp - min(cnt, x) <= 0)	return true;
	return false;
}


void solve(){
	cin >> n >> m;
	LL sum = 0;
	LL z = 0;
	for(int i = 0 ; i < n ; i++){ 
		cin >> a[i];
		sum += a[i];
		z += a[i] / 2;
	}
	
	if(z < m){
		cout << -1 << endl;
		return;
	}

	LL l = 0 , r = sum;
	while(l < r){
		LL mid = (l + r) / 2;

		if(check(mid)) r = mid;
		else l = mid + 1;
 
	}
	if(l == 0 || l == 1){
		cout << -1 << endl;
		return;
	}
	cout << l << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}