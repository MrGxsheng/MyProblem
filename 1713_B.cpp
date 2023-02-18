#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	LL ans = 0;
	for(int i = 0 ; i < n ; i++ ){
		cin >> a[i];
		ans += max(0,a[i] - (i ? a[i - 1] : 0));
		cout << ans << endl;
	} 

	if(ans == *max_element(a.begin(),a.end())) puts("YES");
	else puts("NO");

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
