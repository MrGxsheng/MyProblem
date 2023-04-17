#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];
LL s[N];
LL us[N];
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
		
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == 1) s[i] = 0;
		else s[i] = s[i - 1] + 1;
	}

	for(int i = n ; i >= 1; i--){
		if(a[i] == 1) us[i] = 0;
		else us[i] = us[i + 1] + 1;
	}

	LL ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == 1){
			ans += 1 + s[i - 1] + us[i + 1] + s[i - 1] * us[i + 1];
		}
	}

	cout << ans << endl;
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