#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	
	vector<int> a(n + 1);
	vector<int> win(n + 1);

	int boss = 1;
	win[1] = -1;

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] > a[boss]) boss = i; 
		win[boss]++;
	}

	while(m--){
		int x,y;
		cin >> x >> y;
		if(y < n){
			int ans = win[x];
			if(x > 2)  ans = min(ans,y - x + 2);
			else ans = min(ans,y);
			ans = max(0,ans);
			cout << ans << "\n";
		}else {
			if(x == boss) cout << win[x] + y - n + 1 << "\n";
			else cout << win[x] << "\n";
		}

	}
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
