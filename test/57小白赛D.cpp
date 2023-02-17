#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n;
int a[N];
int m[N];
int gcd(int a , int b){
	return b ? gcd(b , a % b) : a ;
}

void solve(){
	cin >> n;
	int maxx = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		m[a[i]]++;
		maxx = max(maxx,a[i]);
	} 

	int ans = 1;
	for(int i = 2 ; i <= maxx ; i++){
		int cnt =  0;
		for(int j = i ; j <= maxx ; j += i)
			cnt += m[j];
		if(cnt >= 2) ans = max(ans,i);
	}

	cout << ans << endl;
		
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
