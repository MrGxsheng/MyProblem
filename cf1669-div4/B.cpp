#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	map<int,int> mp;
	int ans = -1;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		mp[x] ++;
		if(mp[x] >= 3) ans = x;
	}	
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}