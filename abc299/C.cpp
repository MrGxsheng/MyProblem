#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> n >> s;
	int ans = -1;
	int cnt = 0 , vis = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'o') cnt++;
		else if(s[i] == '-'){
			vis = true;
			if(cnt > 0) ans = max(ans,cnt);
			cnt = 0;
		}
		if(vis && cnt > 0) ans = max(ans,cnt);
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