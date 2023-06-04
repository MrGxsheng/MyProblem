#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> s;
	n = s.size();
	if(count(s.begin(), s.end(),'0') == 0){
		cout << 1ll * n * n << endl;
		return;
	}

	s = s + s;
	LL ans = 0;
	for(int i = 0 , j ; i < n ; i++){
		if(s[i] == '1'){
			j = i;
			while(s[j] == '1')
				j++;
			int d = j - i + 1;
			ans = max(ans,1ll * (d / 2) * (d - d / 2));
			i = j;
		}
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