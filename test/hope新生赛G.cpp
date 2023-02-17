#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 100010;
int n,m;

void solve(){
	cin >> n;
	vector<int> a(2 * n-1);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = n ; i < 2 * n ; i++) a[i] = a[i - n];

	int res = 0; 
	
	for(int i = 0 ; i < n ; i++){
		int s = 0;
		int cnt = 0;
		for(int j = i ; j < i + n; j++){
			s += max(a[j] - (j - i) , 0);
			cnt++;
			if(cnt >= 500) break;
		}

		res = max(res,s);
	}

	for(int i = 2 * n - 1 ; i >= n ; i--){
		int s = 0;
		int cnt = 0;
		for(int j = i ; j > i - n; j--){
			s += max(a[j] - (i - j) , 0);
			cnt++;
			if(cnt >= 500) break;
		}
		res = max(res,s);
	}

	cout << res << endl;


}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
